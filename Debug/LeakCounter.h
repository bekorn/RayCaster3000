//
// Created by Berk on 27.10.2018.
//

#ifndef RAYCASTER3000_LEAKCOUNTER_H
#define RAYCASTER3000_LEAKCOUNTER_H

#include "Config.h"
#include <iostream>
#include <ctype.h>

namespace Debug {

#if !ANALYZE_MEMORY

    template <class DerivedClass>
    class LeakCounter {};

#else

    template<class DerivedClass>
    class LeakCounter {
    protected:
        LeakCounter() {
            created++;
        }

        LeakCounter(const LeakCounter &) {
            created++;
        }

        ~LeakCounter() {
            long unsigned current_simultaneous = created - deleted;

            if (current_simultaneous > max_simultaneous) {
                max_simultaneous = current_simultaneous;
            }

            deleted++;
        }

        static void print_counts() {
            static const char *class_name = derived_class_name;

            while (isdigit(*class_name)) {
                class_name++;
            }

            std::cout << "> Leak Counts of " << class_name << "\n";
            std::cout << "| Total created: " << created << "\n";
            std::cout << "| Total deleted: " << deleted << " (" << created - deleted << " leaked)\n";
            std::cout << "| Max simultaneous: " << max_simultaneous << "\n";
        }

    private:
        static const char *derived_class_name;
        static long unsigned created, deleted, max_simultaneous;

        struct Printer {
            void (*print_function)(void);

            explicit Printer(void (*print_function)(void)) : print_function(print_function) {}

            ~Printer() {
                print_function();
            }
        };

        static Printer printer __attribute__((__used__));
    };

    template<class DerivedClass> const char *LeakCounter<DerivedClass>::derived_class_name = typeid(DerivedClass).name();
    template<class DerivedClass> long unsigned LeakCounter<DerivedClass>::created = 0;
    template<class DerivedClass> long unsigned LeakCounter<DerivedClass>::deleted = 0;
    template<class DerivedClass> long unsigned LeakCounter<DerivedClass>::max_simultaneous = 0;

    template<class DerivedClass> typename LeakCounter<DerivedClass>::Printer LeakCounter<DerivedClass>::printer(
            &LeakCounter<DerivedClass>::print_counts
    );

#endif
}


#endif //RAYCASTER3000_LEAKCOUNTER_H

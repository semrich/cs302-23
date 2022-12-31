// main.cpp

#include "volsort.h"

#include <iostream>

#include <strings.h>
#include <unistd.h>
#include <cstdlib>

#define  MODE_STL       0
#define  MODE_QSORT     1
#define  MODE_MERGE     2
#define  MODE_QUICK     3
#define  MODE_OBLIVIOUS 4

// Utility functions -----------------------------------------------------------

void usage(int status) {
    std::cout << "usage: volsort" << std::endl
              << "    -m MODE   Sorting mode (oblivious, stl, qsort, merge, quick)" << std::endl
              << "    -n        Perform numerical ordering"              << std::endl;
    
    exit(status);
}

void parse_command_line_options(int argc, char *argv[], int &mode, bool &numeric) {
    int c;

    while ((c = getopt(argc, argv, "hm:n")) != -1) {
        switch (c) {
            case 'm':
                if (strcasecmp(optarg, "stl") == 0) {
                    mode = MODE_STL;
                } else if (strcasecmp(optarg, "qsort") == 0) {
                    mode = MODE_QSORT;
                } else if (strcasecmp(optarg, "merge") == 0) {
                    mode = MODE_MERGE;
                } else if (strcasecmp(optarg, "quick") == 0) {
                    mode = MODE_QUICK;
		} else if (strcasecmp(optarg, "oblivious") == 0) {
		  mode = MODE_OBLIVIOUS;
                } else {
                    usage(1);
                }
                break;
            case 'n':
                numeric = true;
                break;
            case 'h':
                usage(0);
                break;
            default:
                usage(1);
                break;
        }
    }
}

// Main execution --------------------------------------------------------------

int main(int argc, char *argv[]) {
    int mode = MODE_STL;
    bool numeric = false;
    List data;
    std::string line;
    
    parse_command_line_options(argc, argv, mode, numeric);

    while (std::getline(std::cin, line)) {
      //data.push_front(line);
    }
    /*
    switch (mode) {
        case MODE_STL:
            stl_sort(data, numeric);
            break;
        case MODE_QSORT:
            qsort_sort(data, numeric);
            break;
        case MODE_MERGE:
            merge_sort(data, numeric);
            break;
        case MODE_QUICK:
            quick_sort(data, numeric);
            break;
    }
    */

    for (Node * curr = data.head; curr != NULL; curr = curr->next) {
        if (numeric) {
            std::cout << curr->number << std::endl;
        } else {
            std::cout << curr->string << std::endl;
        }
    }


    return 0;
}

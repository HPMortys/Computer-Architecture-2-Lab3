#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <map>
#include <string>


int main(int argc, char *argv[]) {
    int res = 0;
	int index = -1;
    
    std::map <char, bool> call;
	
	const struct option lng[] = {
        {"help", 0, NULL, 'h'},
        {"force", 0, NULL, 'f'},
        {"version", 0, NULL, 'v'},
        {"showarg", 1, NULL, 's'},
        {"options", 0, NULL, 'o'},
        {NULL, 0, NULL, 0},
    };

    while ((res = getopt_long(argc, argv, "hfvs:o", lng, &index)) != -1){
		switch (res){
        case 'o': {
            if (call['o'] == false) {
                printf("\nOptions list\n"
                       "-h\t--help\tHelp\n"
                       "-f\t--force\tForce\n"
                       "-v\t--version\tVersion\n"
                       "-s\t--showarg\tShow argument\n"
                       "-o\t--options\tOptions list\n\n"); 				
                call['o'] = true;
				break;
			}
			break;
        }
		case 'h': {
			if (call['h'] == false) {
				printf("Arg: Help\n");
				call['h'] = true;
				break;
			} 
			break;
		}
		case 'f': {
			if (call['f'] == false) {
				printf("Arg: Force\n");
				call['f'] = true;
				break;
			}
			break;
		}
		case 'v': {
			if (call['v'] == false) {
				printf("Arg: Version\n"); 
				call['v'] = true;
				break;
			}
			break;
		}
        case 's': {
            if (call['s'] == false) {
                printf("Showing the argument : %s\n", optarg); 				
                call['s'] = true;
				break;
			}
			break;
        }
		case '?': default: {
			printf("<error> Argument %c does not exist!\n", res);
			break;
			}
        }
		index = -1;
	}
}
#include <stdio.h>
#include <math.h>
#include <string.h>

#define mode_arg 1
#define x_arg 2
#define y_arg 3

double calculate_vector(double x, double y){
    return (sqrt(pow(x, 2) + pow(y, 2)));
}


int main(int argc, char *argv[])
{
    if (argv[x_arg] == NULL || argv[y_arg] == NULL)
    {
        printf("Please provide two numbers (x, y)!\n");
        return 1;
    }
    const char **args = (const char **)argv;

    const char *opt[] = {"-v", "-p"};
    if (strcmp(opt[0], args[mode_arg]) == 0)
    {
        printf("Vector magnitude is: %f", calculate_vector(atof(argv[x_arg]), atof(argv[y_arg])));
    }
    else if(strcmp(opt[1], args[mode_arg]) == 0){
        // Make pythagorean theorem funct
    }
    return 0;

}

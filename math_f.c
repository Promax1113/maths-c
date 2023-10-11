#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define mode_arg 1
#define x_arg 2
#define y_arg 3


double calculate_vector(double x, double y){
    return (sqrt(pow(x, 2) + pow(y, 2)));
}

float calculate_interest(int mode, float time, float capital, float percent) {
    switch (mode)
    {

    case 0:
        printf("%f", capital * (percent / 100) * time);
        break;

    case 1:
        printf("%f", capital * pow(1 + (percent / 100), time));
        break;

    }
    
   
}

double calculate_pythagorean(){

    char choice[1];
    printf("Select letter to solve for (c)athetus, hypo(t)enuse): ");
    scanf("%s", &choice);
    const char *choices[] = {"c", "t"};
    float height;
    float width;
    float hypotenuse;
    if (strcmp(choice, choices[1]) == 0)
    {
        
        printf("Input a number for cathetus a: ");
        scanf("%f", &height);
        printf("Input a number for cathetus b: ");
        scanf("%f", &width);
        float pre_len = pow(height, 2) + pow(width, 2);
        float hy_len = sqrt(pre_len);
        printf("The hypotenuse is: %f", hy_len);

    }
    else if (strcmp(choice, choices[0]) == 0)
    {
        printf("Input a number for cathetus a or b: ");
        scanf("%f", &width);
        printf("Input a number for hypothenuse: ");
        scanf("%f", &hypotenuse);
        float pre_len = (0 - pow(width, 2)) + pow(hypotenuse, 2);
        float hy_len = sqrt(pre_len);
        if (hy_len <= 0){
            printf("Triangle is not possible, length is less or equal to zero (Result = %f)", hy_len);
        } else {
            printf("The height is: %f", hy_len);

        }

    }
}

int main(int argc, char *argv[])
{
    
    const char **args = (const char **)argv;
    

    const char *opt[] = {
        "-v", 
        "-p", 
        "-vs", 
        "-h", 
        "-si" 
    };
    const char *opt_desc[] = {
        "Calculate vector magnitude given x and y.", 
        "Pythagorean theorem.", "Sum of vectors given two vectors in x1 y1 x2 y2 format.", 
        "Shows this message.", 
        "Calculates gain in simple interest."
    };
    int opt_list_len = sizeof(opt) / sizeof(opt[1]);

    if (args[1] == NULL || strcmp(opt[3], args[1]) == 0){
        printf("Avaliable options:\n\n");
        for (int i = 0; i < opt_list_len; i++)
        {
            printf("%i. %s -> %s\n", i + 1, opt[i], opt_desc[i]);
        }
        
    }

    if (strcmp(opt[0], args[mode_arg]) == 0)
    {
        if (argv[x_arg] == NULL || argv[y_arg] == NULL)
        {
            printf("Please provide two numbers (x, y)!\n");
            return 1;
        }
        printf("Vector magnitude is: %f", calculate_vector(atof(argv[x_arg]), atof(argv[y_arg])));
    }
    else if(strcmp(opt[1], args[mode_arg]) == 0){
        calculate_pythagorean();
    }

    else if (strcmp(opt[2], args[mode_arg]) == 0)
    {
        if (argv[x_arg] == NULL || argv[y_arg] == NULL)
        {
            printf("Please provide two numbers (x, y)!\n");
            return 1;
        }
        printf("The sum of vectors (%2.6f, %2.6f) and (%2.6f, %2.6f) magnitude is: %f",atof(args[x_arg]), atof(args[x_arg + 2]), atof(args[y_arg]), atof(args[y_arg + 2]), calculate_vector(atof(args[x_arg + 2]) + atof(args[x_arg]), atof(args[y_arg + 2]) + atof(args[y_arg])));
    }
    else if (strcmp(opt[4], args[mode_arg])) {
        int mode;
        printf("Choose the mode, (1) Simple, (2) Compound");
        scanf("%i", &mode);
        calculate_interest(mode, atof(args[x_arg]), atof(args[y_arg]), atof(args[y_arg + 1]));
    }
    return 0;

}

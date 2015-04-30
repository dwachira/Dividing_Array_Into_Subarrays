 /*********************************************************************************
 *                   Mureithi David Wachira                               		  *
 *                   P15/2204/2011                                        		  *
 *                                                                        		  *
 *                   University of Nairobi                                		  *
 *                   School of Computing & Informatics                    		  *
 *                                                                        		  *
 *                   Course: DATA STRUCTURES AND ALGORITHMS   (CSC 211)   		  *
 *                   Date:   Tuesday 01st October 2013                  		  *
 *                                                                        		  *
 *                   Develop an algorithm with the following characteristics:	  *
 *                   •	An array of a variable size (n)               	          *
 *                   •	A variable (y) of type integer                 	          *
 *                   •	The algorithm should divide the array into n/y parts      *
 *                   •	Calculate the average for each part                    	  *
 *                   •	Finally find the maximum value among the averages      	  *
 *                   •	Discuss about the number of operations for the algorithm  *
 *                                                                                *
 *********************************************************************************/



 #include<stdio.h> /* C Standard Input and Output Library*/

     /*Variable declarations*/
     int y;                                                 /*	Declaration of a variable called y of type integer. */
     double sum=0;                                          /*	Declaration of a variable called sum of type double and initialize it to zero. */
     double average=0;                                      /*	Declaration of a variable called average of type double and initialize it to zero. */
     double maximum_average=0;                              /*	Declaration of a variable called maximum_average of type double and initialize it to zero. */
     double sub_arrays;                                     /*	Declaration of a variable called sub_arrays to hold the result of n/y which is the number of sub-arrays. */
     int array_input_counter, results_array_input_counter;  /*	Declaration of two counters */
     int counter_finding_max_in_loop=0;                     /*	Declaration of a counter and initialization*/
     int n;                                                 /*	Declaration of a global variable called n of type integer - the size of the array */

 int main(void)/* The main method*/
 {
    /* Brief detail on the screen about the program*/
    printf(" /*************************************************************************\n *                                                                        *\n *       Mureithi David Wachira                               		  *\n *       P15/2204/2011                                        		  *\n *                                                                        *\n *       University of Nairobi                                		  *\n *       School of Computing & Informatics                    		  *\n *                                                                        *\n *       Course: DATA STRUCTURES AND ALGORITHMS   (CSC 211)   		  *\n *       Date:   Tuesday 01st October 2013                  		  *\n *                                                                        *\n *       Develop an algorithm with the following characteristics:	  *\n *       	An array of a variable size (n)               	          *\n *       	A variable (y) of type integer                 	          *\n *       	The algorithm should divide the array into n/y parts      *\n *       	Calculate the average for each part                    	  *\n *       	Finally find the maximum value among the averages      	  *\n *      	Discuss about the number of operations for the algorithm  *\n *                                                                        *\n **************************************************************************/\n            ");

    printf("\nPlease enter the size of the array (n): \n");/* Prompt to instruct user to enter size n */
    scanf("%d",&n);                                        /* Capture of the integer to be assigned to n*/

    /*Variable declaration*/
    int array_of_numbers[n];                               /*  Declaration of an array of n size, n being an integer that is known. */

    printf("\nPlease enter y: \n");                        /* Prompt to instruct use to enter y */
    scanf("%d",&y);                                        /* Capture of the integer to be assigned to variable y*/

    sub_arrays=((double)n/(double)y);                      /* Divide n by y and round off the value before assigning it to the variable called sub_arrays*/

          if ( sub_arrays - (int)sub_arrays > 0.0)         /* Determining whether the subarrays value has decimals*/
          {
           printf("\nThe value \"%.2lf\" has decimal points after it. It will be rounded off to %d.\nTherefore the array will be divided into %d sub arrays \n \n",sub_arrays, ((int)sub_arrays)+1, ((int)sub_arrays)+1);
          }
          else                                            /* In the case that the sub arrays value has no decimals*/
          {
           printf("\nThe array will be divided into %d sub arrays \n",(int)sub_arrays);
          }

    printf("\nPlease enter the numbers in the array: \n");     /* Prompt to instruct use to enter array elements */

    double array_of_results[(int)sub_arrays][2];               /* Declaration of a 2-dimensional array to hold the sums and averages*/

    results_array_input_counter = 0;                           /* Initialization of the counter for looping through the array of results*/

    for ( array_input_counter = 1 ; array_input_counter <= n; array_input_counter++ )          /* Loop to capture the numbers and also calculate the sum of sub arrays*/
     {       scanf( "%d", &array_of_numbers[array_input_counter] );                            /* Capturing of the numbers through scanf()*/
             sum= sum + array_of_numbers[array_input_counter] ;                                /* Incrementation of the value held by sum as more numbers are captured*/

             if (array_input_counter%y==0 && array_input_counter!=0)                           /* Checking if one sub array is complete*/
                    {   array_of_results [results_array_input_counter][0] = sum;               /* Assignment of the value of sum of a particular subarray to the array of results*/
                        //printf("\nThe value \"%.2lf\" entered in the array as sum for sub-array (%d)", array_of_results [results_array_input_counter][0], (results_array_input_counter+1));
                        average = sum/ y;                                                      /* Calculation of the average*/
                        array_of_results [results_array_input_counter][1] = average;           /* Assignment of the value of the average of a particular sub array to the array of results*/
                        //printf("\nThe value \"%.2lf\" entered in the array as mean for sub-array(%d)\n\n", array_of_results [results_array_input_counter][1], (results_array_input_counter+1) );
                        sum=0;                                                                 /* Initialization of the value of sum after completing one sub array*/
                        average=0;                                                             /* Initialization of the value of average after completing one sub array*/
                        results_array_input_counter=results_array_input_counter+1;             /* Incrementation of the counter by 1*/
                    }
    }


    if (((int)sub_arrays * y)!=n)
           {
              array_of_results [results_array_input_counter][0] = sum;
              //printf("\nThe value \"%.2lf\" entered in the array as sum for sub-array (%d)", array_of_results [results_array_input_counter][0], (results_array_input_counter+1));
              average = sum/ (n-((int)sub_arrays * y));
              array_of_results [results_array_input_counter][1] = average;
              //printf("\nThe value \"%.2lf\" entered in the array as mean for sub-array(%d)\n\n", array_of_results [results_array_input_counter][1], (results_array_input_counter+1) );

            }

       /* Loop to determine the maximum value among the averages of the sub arrays*/
       for ( counter_finding_max_in_loop = 0 ; counter_finding_max_in_loop <= ((int)((double)n/(double)y)); counter_finding_max_in_loop++ )
        { if (array_of_results [counter_finding_max_in_loop][1]>maximum_average )
              {maximum_average= array_of_results [counter_finding_max_in_loop][1];}
        }


            printf("\n The maximum average is %.2lf\n--------------------------------------------------------------------------------\n ",maximum_average);
            printf("\n\n Let us visualize the array\n");
            printf( " [ ");
            for ( array_input_counter = 1 ; array_input_counter <= n; array_input_counter++ )
                     {    printf( "%d ", array_of_numbers[array_input_counter] );
                          if (array_input_counter%y==0 && array_input_counter!=n)
                             {printf( "] - [ ");}
                     }
            printf( "]\n");
            printf("\n\n The averages are as follows :\n");

            if (sub_arrays - ((int)((double)n/(double)y)) > 0.0)
                 {

                    for ( array_input_counter = 0 ; array_input_counter <= (int)sub_arrays; array_input_counter++ )
                             {    printf( "  [ %.2lf ]   ", array_of_results [array_input_counter][1] );

                             }
                    printf( "\n\n--------------------------------------------------------------------------------\n");
                 }
            else if (sub_arrays - ((int)((double)n/(double)y)) <= 0.0)
                 {

                    for ( array_input_counter = 0 ; array_input_counter < (int)sub_arrays; array_input_counter++ )
                             {    printf( "  [ %.2lf ]   ", array_of_results [array_input_counter][1] );

                             }
                    printf( "\n\n--------------------------------------------------------------------------------\n");
                 }




}

//main.c


#include <stdint.h>
#include "BatterySOC.h"
#include <stdio.h>
#define Tmin (temperature_t)(-40)
#define Tmax (temperature_t)55


     index_t str[100];
     index_t soc = 0;
	 // Create test cases for temperature between Min to Max at range of Cell voltage
     // between VcellMax and VcellMin 
     temperature_t temperature = Tmin ; 
      Vcell_t cellV = CELLVMIN; 
	  index_t ret; // 
      
      
      index_t rowV = 200;
      index_t rowT = 200;
      index_t countV = 0;
      index_t countT = 0;

	  int main(int argc, char **argv)

{
		  index_t retsoc = getSOC( 3800,25, 0);
		  printf(" %d \n", retsoc);
		  
		  FILE *fp;
		  fp = fopen("soc.csv", "w+c");

		  if (fp == NULL)
		  {
			  printf("\n fail to open file");
			  return 1;
		  }

		  		     
 //  fprintf(fp, "retsoc=====%d,\n", retsoc);  // for place holder
 //  fclose(fp); // or for the paranoid: if (fclose (fout) == eof) rc = 0;
 //  int data;
 //  scanf("%d", &data);
 //     
 //  return ret;
 //}

     
   
          fprintf(fp, "%d,", 9999);  // for place holder
	
       
      for( index_t idx =  0;  idx < 200 ; idx ++)
         {
             uint16_t rowOne = idx * STEPV + CELLVMIN;
               if  (( rowOne  >= (uint16_t)CELLVMIN)  && (rowOne  <= (uint16_t)CELLVMAX))
               {                  
				   countV++;
                    fprintf(fp, "%d,", rowOne);
               }
         }
          
        // GET SOC
        for ( index_t j = 0; j < rowT ; j++)      
            { 
            printf("in top level For \n");
            printf("temp = %d, \n", temperature);
            
          //  fprintf(fp," @Temperature of %d \n", temperature); 
            fprintf(fp,"\n %d, ", temperature);
            
            cellV = CELLVMIN;  // reset cellVmin for next iteration
            
              if ((temperature < (Tmin)) || (temperature >  (Tmax) ))  // done  
           {
        printf ( "out of temperature range \n");
         return 0;
         }
			  temperature = j == 0 ? temperature :  temperature + STEPT;
                // do once at least for start temperature point
                                            
                   for (index_t i = 0 ; i < rowV; i ++)
               {
                if  ((cellV < CELLVMIN)  || (cellV > CELLVMAX))
                       {
                      break;
                    }  
                    ret = getSOC(cellV,temperature, soc);              
                 
                  fprintf(fp,"%03d, ", ret);                 
                  cellV = cellV + STEPV ;
                }                                                            
            }   
                          
            fclose(fp);
             return 0;   
    } 
            
           
        
		
#include<stdio.h>
#include<windows.h>
#include<time.h>

int main(){
	
    system("color 3f");
    int pin=1234, enteredpin, option, count=0, amount=1;
    float balance=5000;
    int countinuetransaction=1;

    time_t now;
    time(&now);
    printf("\n");
    printf("\t\t\t\t\t    %s",ctime(&now));
    printf("\n\t\t\t ==========*WELCOME TO ATM MACHINE*==========");

    start:

    while(pin!=enteredpin){
    	printf("\n Please Enter Your Pin:");
		scanf("%d",&enteredpin);
    	if(enteredpin!=pin){
    		printf("Invalid Pin...!");
		}
		count++;
		if(count==3 && pin!=enteredpin){
			exit(0);
		}
	}
	
	abc:
		
	printf("\n\t\t\t    ==========*TRANSACTION AVAILABLE*==========");
	printf("\n\n\t\t1.Deposit");
	printf("\n\t\t2.Withdraw");
	printf("\n\t\t3.Pin Change");
	printf("\n\t\t4.Check Balance");
	printf("\n\t\t5.Exit");
    printf("\n\n\t Please Select The Option:");
    scanf("%d",&option);
    
    switch(option){
    	//DEPOSIT SECTION
    	case 1:{
    			printf("\n\n\t Enter The Deposit Amount:");
    			scanf("%d",&amount);
    			balance=balance+amount;
    			printf("\n\n\t You Have Deposited Amount is Rs.%d. Your New Balance is Rs.%.2f",amount,balance);
    	        amount=1;
	 goto abc;	
     		}
     		
     		//WITHDRAW SECTION
    	case 2:{  
		        while(amount%500!=0){
    			printf("\n\n\t\tEnter The Withdraw Amount:");
    			scanf("%d",&amount);
    			if(amount%500!=0)
    			printf("\n\t\t\t Sorry! The Amount Should Be Multiple Of Rs.500.00");
            }
	                 
				if(balance<=amount){
				printf("\n\t\t Sorry Insufficient Balance:");
	            amount=1;
	            
		 		}
			
				else{
				balance=balance-amount;
				printf("\n\t\tYou Have Withdraw Rs.%d. Your New Balance is Rs.%.2f",amount,balance);
	            amount=1;
						
				}
				
     	
	 	goto abc;
	 	break;
	 	
				}
				
			//PIN UPDATE SECTION	
		case 3:{
				printf("\n\t\tEnter a New Pin");
				scanf("%d",&pin);
				printf("\n\t\tYour Pin is Updated Successfully...");
				printf("\\n\n\t\tLogin Again...");
				count=0;
				goto start;
				break;
				}
				
			//CHECK BALANCE SECTION
		case 4:{
				printf("\n\t\t Your Balance is Rs.%.2f",balance);
				goto start;
				break;
		    	}
		
		   //EXIT SECTION
		case 5:{
			
			printf("\n\t\t.......***THANK YOU***......");
			break;
	    	}
		
		default: {
			printf("\n\t\tYou Have Entered Wrong Option.");
			printf("\n\t\tPlease Enter The Correct Option.");
			goto start;	
    		}
    }
   
	
  
    
    return 0;
}
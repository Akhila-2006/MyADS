#include<stdio.h>
int main()
{
	int ch,n,k,a;
	int amount=2000;
	do{
		printf("**ATM services**\n");
		printf("1.Balance checking\n");
		printf("2.Money Deposit\n");
	    printf("3.Withdrawal\n");
	    printf("Enter your choice : ");
	    scanf("%d",&ch);
	    switch(ch){
	    	case 1:
	    		printf("Your balance is : %d\n", amount);
	    		break;
	    	case 2:
	    		printf("Enter the amount to deposit :  ");
	    		scanf("%d",&n);
	    		amount=amount+n;
	    		printf("Your amount after deposition is :  %d\n",amount);
	    		break;
	    	case 3:
	    		
	    		printf("Enter the amount how much you want to draw: ");
	    		scanf("%d",&k);
	    		if(k>(amount-500))
	    		{
	    			printf("Invalid amount\n");
				}
				else
				{
					printf("Withdrawal amount is : %d\n",k);
					printf("Please collect cash\n");
					amount=amount-k;
					printf("your present amount is :  %d\n",amount);
				}
				break;
				case 4:
					printf("Thank you\n");
					break;
					default:
						printf("Invalid choice\n");
		}
		printf("Do you want to continue transictions press N: ");
		fflush(stdin);
		scanf("%c",&a);
	}while(a=='N');
}

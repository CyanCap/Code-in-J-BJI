#include<stdio.h>
int main()
{
	int i=1;
	float P1,P2,P3,T;
	for(i=1;i <= 3;i++)
	{
		float Price_product=0.0,Price_item=0.0;
		float Payment_total=0.0,Payment_discount=0.0;
		char Discount_status='a';
		int NumProducts=1,NumItems=1,Discount_coupon=0,Discount_reduced=0;
		printf("Please input the price for the product:");
		scanf("%f", &Price_product);
		printf("Please input the number of the product you want to order:");
		scanf("%d",&NumProducts);
		printf("Please input the number of items for each product:");
		scanf("%d",&NumItems);
    	printf("Is there any discount? If it is, please input Y, otherwise input N\n");
    	scanf("%c",&Discount_status);
    	Discount_status=getchar();
    	printf("Discount_status:%c \n",Discount_status);
    	if(Discount_status == 'Y')
		{
			printf("Please input discount coupon and reduced amount. \n");
    	    printf("For example, Total Payment for an order at 199 RMB(Discount_coupon) can be reduced 60 RMB (Discount_reduced).\n");
    	    printf("\n Discount_coupon = ");
    	    scanf("%d",&Discount_coupon);
    	    printf("\n Discount_reduced = ");
			scanf("%d",&Discount_reduced);
			printf("\n\nThank you! Your input: Discount_coupon = %d,Discount_reduced = %d\n",Discount_coupon, Discount_reduced);
		}else{
			if(Discount_status == 'N')
			Discount_reduced = 0;
			else{
				printf("Input WRONG information for existing discount.");
				return 1;
   			}
		}
		Payment_total = Price_product * NumProducts;
		printf("Payment before any discount:%f\n",Payment_total);
		if(Discount_status == 'Y' && Payment_total >= Discount_coupon)
		{
			Payment_discount = Payment_total - Discount_reduced;
			Price_item = Payment_discount / (NumItems * NumProducts);
			printf("Payment after discount:%f\n",Payment_discount);
			printf("Final price for each item after the discount:%f\n",Price_item);
		}else{
			if(Discount_status == 'N')
			{
				Price_item = Payment_total / (NumItems * NumProducts);
				printf("Final price for each item without the discount:%f\n\n",Price_item);
			}
		}
		if(i == 1)
		{
			P1=Price_item;
		}else if(i == 2)
		{
			P2=Price_item;
		}else if(i == 3)
		{
			P3=Price_item;
		}
	}
	printf("%f %f %f\n",P1,P2,P3);
	if(P1 >= P2)
		{
			T=P1;
			P1=P2;
			P2=T;
		}
		if(P1 >= P3)
		{
			T=P1;
			P1=P3;
			P3=T;
		}
		if(P2 >= P3)
		{
			T=P2;
			P2=P3;
			P3=T;
		}
	printf("Choose %f",P1);
	
	return 0;
}



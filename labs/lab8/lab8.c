#include <stdio.h>

const double RATE = .0825;
const double TV = 	400.00;
const double VCR = 220.00;
const double REMOTE_CONTROL = 35.20;
const double CD_PLAYER = 300.00;
const double TAPE_PLAYER = 150.00;





void calculate_total(double price1, double price2, 
						double price3, double price4, double price5);

void print_total(double subtotal, double tax, double total);



void calculate_items(int item1, int item2, 
						int item3, int item4, int item5);
void input();

int main()
{
	input();



	return 0;

}


void print_total(double subtotal, double tax, double total)
{
	printf("\t\t\t------------ \t -------\n");
	printf("\t\t\t%s\t%.2lf\n","SUBTOTAL", subtotal);
	printf("\t\t\t%s\t\t%.2lf\n","TAX", tax);
	printf("\t\t\t%s\t\t%.2lf\n","TOTAL", total);

}


void calculate_total(double price1, double price2, 
						double price3, double price4, double price5)
{
	double subtotal = price1 + price2 + price3 + price4 + price5;
	double tax = subtotal * RATE;
	double total = subtotal + tax;

	print_total(subtotal, tax, total);

}
void calculate_items(int item1, int item2, 
						int item3, int item4, int item5)
{
	double tv_price = item1 * TV;
	double vcr_price = item2 * VCR;
	double remote_price = item3 * REMOTE_CONTROL;
	double cd_price = item4 * CD_PLAYER;
	double tape_price = item5 * TAPE_PLAYER;

	
	printf("QTY\tDESCRIPTION\t UNIT PRICE \t TOTAL\n");
	printf("---\t-----------\t ----------  \t -----\n");

	//printf("%f", tv_price);
	printf("%d\t %s\t\t %.2lf\t\t  %.2lf\t\n", item1, "TV", TV, tv_price);
	printf("%d\t %s\t\t %.2lf\t\t  %.2lf\t\n", item2, "VCR", VCR, vcr_price);
	printf("%d\t %s\t\t %.2lf\t\t  %.2lf\t\n", item3, "REMOTE", REMOTE_CONTROL, remote_price);
	printf("%d\t %s\t\t %.2lf\t\t  %.2lf\t\n", item4, "CD", CD_PLAYER, cd_price);
	printf("%d\t %s\t %.2lf\t\t  %.2lf\n", item5, "TAPE PLAYER", TAPE_PLAYER, tape_price);




	
	calculate_total(tv_price, vcr_price, remote_price, cd_price, tape_price);
}
void input()
{
	int tv_sold, vcr_sold, remote_sold, cd_sold, tape_sold;

	
	printf("How many TVs were sold? ");
	scanf("%d", &tv_sold);

	printf("How many VCRs were sold? ");
	scanf("%d", &vcr_sold);

	printf("How many Remote Controls were sold? ");
	scanf("%d", &remote_sold);

	printf("How many CDs were sold? ");
	scanf("%d", &cd_sold);

	printf("How many Tape Controllers were sold? ");
	scanf("%d", &tape_sold);

	calculate_items(tv_sold, vcr_sold, remote_sold, cd_sold, tape_sold);
}

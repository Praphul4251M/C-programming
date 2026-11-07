// Problem statement: Read the prices of three items and their quantities. Display each line total, the subtotal, 5% tax, and final payable amount to two decimal places. Assume nonnegative inputs. Require the output to make the contribution of each purchased item visible before calculating the bill. Explain through the displayed values why intermediate amounts should remain floating-point values rather than being rounded to integers.

#include <stdio.h>

int main(void) {
  double price_a;
  double price_b;

  double price_c;
  int quantity_a;
  int quantity_b;
  int quantity_c;

  if (scanf("%lf %d %lf %d %lf %d", &price_a, &quantity_a, &price_b, &quantity_b, &price_c, &quantity_c) != 6) {
    return 1;
  }

  double total_a = price_a * quantity_a;

  double total_b = price_b * quantity_b;

  double total_c = price_c * quantity_c;

  double subtotal = (total_a + total_b) + total_c;

  double tax = subtotal * 0.05;

  printf("A: %.2f\nB: %.2f\nC: %.2f\n", total_a, total_b, total_c);
  printf("Subtotal: %.2f\nTax: %.2f\nPayable: %.2f\n", subtotal, tax, subtotal + tax);

  return 0;
}
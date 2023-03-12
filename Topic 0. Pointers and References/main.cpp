#include <iostream>
//Program that change the price of an item
//after applying the VAT rate
void applyVatRate(double& currentPrice, double vatRatePercent)
{
    currentPrice *= (1 + vatRatePercent/100);
}

void swap(int* first, int* second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

int main() {
    const double BG_VAT_TAX_RATE_PERCENT = 20.0;
    double milkPrice = 2.59;

    applyVatRate(milkPrice, BG_VAT_TAX_RATE_PERCENT);

    printf("Milk price after VAT rate applied is %.2f bgn\n", milkPrice);
}

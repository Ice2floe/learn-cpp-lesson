#include<iostream>

struct Advertise
{
  int quantAds {145};
  double userAds {0.67};
  double earnAverage {0.5};
};

void printPriceMarket (const Advertise& ads)
  {
    double total {ads.quantAds*ads.userAds*ads.earnAverage};

    std::cout << "Number of Ads: " << ads.quantAds << '\n';
    std::cout << "Percentage of users " << ads.userAds << '\n';
    std::cout << "Price per Ad: " << ads.earnAverage << '\n';
    std::cout << "Total earning: " << total << '\n';
}

int main ()
  {
    printPriceMarket (Advertise{});
    return 0;
  }

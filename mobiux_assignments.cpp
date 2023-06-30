#include<bits/stdc++.h>

#include <fstream>

#include <sstream>

using namespace std;

struct SaleEntry {
  string date;
  string SKU;
  int unitPrice;
  int quantity;
  int totalPrice;
};

vector < SaleEntry > getSalesData(const string & path) {
  vector < SaleEntry > salesRecords;
  ifstream file(path);
  string line;
  getline(file, line);
  while (getline(file, line)) {
    stringstream ss(line);
    string date, SKU, unitPriceStr, quantityStr, totalPriceStr;
    getline(ss, date, ',');
    getline(ss, SKU, ',');
    getline(ss, unitPriceStr, ',');
    getline(ss, quantityStr, ',');
    getline(ss, totalPriceStr, ',');
    int unitPrice = stoi(unitPriceStr);
    int quantity = stoi(quantityStr);
    int totalPrice = stoi(totalPriceStr);
    salesRecords.push_back({
      date,
      SKU,
      unitPrice,
      quantity,
      totalPrice
    });
  }
  file.close();
  return salesRecords;
}

// calculate the total sales of the store
int calculateTotalSales( vector < SaleEntry > & salesRecords) {
  int totalSales = 0;
  for ( auto & entry: salesRecords) {
    totalSales += entry.totalPrice;
  }
  return totalSales;
}

//  calculate the month-wise sales totals

unordered_map < string, int > calculateMonthlySalesTotals( vector < SaleEntry > & salesRecords) {
  unordered_map < string, int > monthlySales;
  for ( auto & entry: salesRecords) {
    string month = entry.date.substr(5, 2);
    monthlySales[month] += entry.totalPrice;
  }
  return monthlySales;
}

// most popular item (most quantity sold) in each month

unordered_map < string, pair < string, int >> findMostPopularItem( vector < SaleEntry > & salesRecords) {
  unordered_map < string, pair < string, int >> popularItems;
  unordered_map < string, map < string, int >> allitemInMonth;
  for ( auto & entry: salesRecords) {
    string month = entry.date.substr(5, 2);
    allitemInMonth[month][entry.SKU] += entry.quantity;
  }

  for (auto it1: allitemInMonth) {
    string most_pop_item;
    int mx = -1;
 
    for (auto it2: it1.second) {
      if (mx < it2.second) {
        most_pop_item = it2.first;
        mx = it2.second;
      }
    }
    popularItems[it1.first] = {
      most_pop_item,
      mx
    };
  }

  return popularItems;
}

// items generating the most revenue in each month

unordered_map < string, pair < string, int >> findItemsGeneratingMostRevenue( vector < SaleEntry > & salesRecords) {
  unordered_map < string, pair < string, int >> revenueItems;
  unordered_map < string, map < string, int >> allitemInMonth;
  for ( auto & entry: salesRecords) {
    string month = entry.date.substr(5, 2); 
    allitemInMonth[month][entry.SKU] += entry.totalPrice;
  }
  for (auto it1: allitemInMonth) {
    string salesitemGen;
    int mx = -1;
   
    for (auto it2: it1.second) {
      if (mx < it2.second) {
        salesitemGen = it2.first;
        mx = it2.second;
      }

    }
    revenueItems[it1.first] = {
      salesitemGen,
      mx
    };
   

  }

  return revenueItems;
}


//  min, max, and average number of orders for the most popular item each month

unordered_map < string, pair < int, pair < int, double >>> findOrderStatsForPopularItem( vector < SaleEntry > & salesRecords,
  unordered_map < string, pair < string, int >> & popularItems) {
  unordered_map < string, pair < int, pair < int, double >>> orderStats;
  for ( auto  monthPopularItem: popularItems) {
     string month = monthPopularItem.first;
     string popularItem = monthPopularItem.second.first;
    vector < int > orderCounts;
    for ( auto  entry: salesRecords) {
      if (entry.date.substr(5, 2) == month && entry.SKU == popularItem) {
        orderCounts.push_back(entry.quantity);
      }
    }
    int minOrders = * min_element(orderCounts.begin(), orderCounts.end());
    int maxOrders = * max_element(orderCounts.begin(), orderCounts.end());

    double xt = static_cast < double > (accumulate(orderCounts.begin(), orderCounts.end(), 0));
 
    double avgOrders = xt / orderCounts.size();
    orderStats[month] = {
      minOrders,
      {
        maxOrders,
        avgOrders
      }
    };
  }
  return orderStats;
}

int main() {
  vector < SaleEntry > salesRecords = getSalesData("/uploads/tableConvert.com_o84nhy (1).csv"); 

 

  int totalSales = calculateTotalSales(salesRecords);
  cout << "Total sales of the store: " << totalSales << endl << endl;

  unordered_map < string, int > monthlySalesTotals = calculateMonthlySalesTotals(salesRecords);
  cout << "Month-wise sales totals:" << endl;
  for ( auto & monthSales: monthlySalesTotals) {
    cout << monthSales.first << ": " << monthSales.second << endl;
  }
  cout << endl;

  unordered_map < string, pair < string, int >> popularItems = findMostPopularItem(salesRecords);
  cout << "Most popular item in each month:" << endl;
  for ( auto & monthPopularItem: popularItems) {
    cout << monthPopularItem.first << ": " << monthPopularItem.second.first << " (" << monthPopularItem.second.second << ")" << endl;
  }
  cout << endl;

  unordered_map < string, pair < string, int >> revenueItems = findItemsGeneratingMostRevenue(salesRecords);
  cout << "Items generating most revenue in each month:" << endl;
  for ( auto & monthRevenueItem : revenueItems) {
    cout << monthRevenueItem.first << ": " << monthRevenueItem.second.first << " (" << monthRevenueItem.second.second << ")" << endl;
  }
  cout << endl;

  unordered_map < string, pair < int, pair < int, double >>> orderStats = findOrderStatsForPopularItem(salesRecords, popularItems);
  cout << "Order stats for the most popular item each month:" << endl;
  for ( auto & monthOrderStats: orderStats) {
    auto orderstate = monthOrderStats.second;
    cout << monthOrderStats.first << ": " <<
      "Min: " << orderstate.first << ", " <<
      "Max: " << orderstate.second.first << ", " <<
      "Average: " << (orderstate.second.second) << endl;
  }

  return 0;
}

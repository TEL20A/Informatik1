#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/// Soll den Vektor v so umsortieren, dass zuerst alle Elemente
/// kommen, die <= p sind und dann alle Elemente, die >p sind.
/// Hinweis: p muss genau einmal in der Liste vorkommen.
vector<int> partition(vector<int> v, int p);

/// Soll den Vektor v so filtern, dass er nur noch Elemente enthält,
/// die <p sind.
vector<int> filterk(vector<int> v, int p);

/// Soll den Vektor v so filtern, dass er nur noch Elemente enthält,
/// die >p sind.
vector<int> filterg(vector<int> v, int p);


vector<int> quicksort(vector<int> v);


void print(vector<int> v)
{
  if (v.empty()) { return; }
  cout << v[0] << " ";
  v.erase(v.begin());
  print(v);
}


int main() {

  vector<int> v1 = { 15,17,5,23,2,42,1,38 };

  v1 = quicksort(v1);

  print(v1);
  cout << endl;

  vector<int> v2 = { 15,17,5,23,2,42,1,38 };
  sort(v2.begin(), v2.end());
  print(v2);
}


vector<int> quicksort(vector<int> v)
{
  if (v.empty()) { return v; }

  int p = v[0];
  vector<int> links = filterk(v,p);
  vector<int> rechts = filterg(v,p);

  links = quicksort(links);
  rechts = quicksort(rechts);

  links.push_back(p);
  for (auto el:rechts)
  {
    links.push_back(el);
  } 
  return links;
}


vector<int> partition(vector<int> v, int p)
{
  vector<int> links = filterk(v,p);
  vector<int> rechts = filterg(v,p);

  links.push_back(p);
  for (auto el:rechts)
  {
    links.push_back(el);
    //links.push_back(rechts); // Achtung: FALSCH, Typfehler, man kann keinen Vektor als Element in einen anderen Vektor einfügen!!!
  } 
  return links;
}

vector<int> filterk(vector<int> v, int p)
{
  for (int i=0; i< v.size(); i++)
  {
    if (v[i] >= p) { v.erase(v.begin() + i); i--; }
  }
  return v;
}

vector<int> filterg(vector<int> v, int p)
{
  vector<int> ergebnis;

  for (auto el : v)
  {
    if (el > p) { ergebnis.push_back(el); }
  }

  return ergebnis;
}
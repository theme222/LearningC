#include <stdexcept>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <unordered_map>
#include "map_bst_grader.h"
#include "student.h"
//#pragma once
//


template <typename KeyT,
          typename MappedT,
          typename CompareT >
bool CP::map_bst<KeyT,MappedT,CompareT>::check_new_node = false;

int main() {
  int n,k,mode;
  scanf("%d %d %d\n",&n,&k,&mode);
  std::vector<int> v(n);

  CP::map_bst<int,int> m1,m2;
  for (int i = 0;i < n;i++) {
    int a;
    scanf("%d",&a);
    v[i] = a;
    m1[a] = -a;
  }


  //save address
  std::unordered_map<int,void*> address;
  m1.save_address(address);


  if (mode == 1) m1.check_new_node = true;
  m2 = m1.split(k);

  printf("Split Done\n");
  //check
  bool ok = true;
  for (auto &x : v) {
    if (x < k && (m1.find(x) == m1.end() || m2.find(x) != m2.end()) ) {
      ok = false;
      break;
    }
    if (x >= k && (m2.find(x) == m2.end() || m1.find(x) != m1.end() ) ) {
      ok = false;
      break;
    }
  }

  printf("Check Data Done\n");
  if (mode == 1) {
    //we also check address
    if (!m1.check_address(address)) ok = false;
    if (!m2.check_address(address)) ok = false;
  }
  printf("Check Address Done\n");
  if (ok) {
    printf("OK aslkdfjaqo34thjslakdjfal\n");
  } else {
    printf("WRONG\n");
  }

	return 0;
}


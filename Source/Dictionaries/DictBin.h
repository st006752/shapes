#pragma once
#include "BinTree.h"
#include "DictPara.h"


template < typename key, typename value >
class Dict {
public:
	Dict() = default;
  
	value operator[](const key&) {
    DictPara<key, value> search(k, value{});
    auto found = tree_.find(search);
    if (found != tree_.end()) {
      return (*it).get_value();
    }
    tree.insert_(search);
    return value{};
  }

	void insert(const key& k, const value& v) {
    tree.insert_(DictPara<key, value>(k, v));
  }

private:
	BinTree<DictPara<key, value>> data_;
};


#pragma once
#include "Dictionaries/DictPara.h"


template < typename key, typename value >
class ABCDict {
public:
	virtual value operator[](const key&) = 0;

	virtual void insert(const key&, const value&) = 0;
};


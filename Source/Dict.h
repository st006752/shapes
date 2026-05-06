#pragma once
#include "Array.h"
#include "DictPara.h"


template < typename key, typename value >
class Dict {
public:
	Dict() = default;

	// Обращение по ключу
	value operator[](const key&);

	// Добавление сопоставления
	void insert(const key&, const value&);

private:
	Array< DictPara<key,value> > data_;
};


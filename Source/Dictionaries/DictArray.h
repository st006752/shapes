#pragma once
#include <stdexcept>

#include "Array.h"
#include "Dictionaries/ABC.h"


template < typename key, typename value >
class ArrayDict: public ABCDict<key, value> {
public:
	ArrayDict() = default;

	// Обращение по ключу
	value operator[](const key&) override;

	// Добавление сопоставления
	void insert(const key&, const value&) override;

private:
	Array< DictPara<key,value> > data_;
};

template < typename key, typename value >
value ArrayDict<key, value>::operator[](const key& searchKey) {
	for (typename Array< DictPara<key, value> >::iterator it = data_.begin();
		 it != data_.end();
		 ++it) {
		if ((*it).get_key() == searchKey) {
			return (*it).get_value();
		}
	}
	throw std::out_of_range("Key not found in Dict");
}

template < typename key, typename value >
void ArrayDict<key, value>::insert(const key& newKey, const value& newValue) {
	for (typename Array< DictPara<key, value> >::iterator it = data_.begin();
		 it != data_.end();
		 ++it) {
		if ((*it).get_key() == newKey) {
			*it = DictPara<key, value>(newKey, newValue);
			return;
		}
	}
	data_.push_back(DictPara<key, value>(newKey, newValue));
}

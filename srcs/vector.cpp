#include "../includes/vector.hpp"


vector::vector() : _size(0), _capacity(0) {}
vector::vector(size_type size, value_type val = value_type() ): _size(0), _capacity(0) {}
vector::~vector() {}

void    vector::doublingCapacity() {
    _capacity = (!_capacity) ? (1) : _capacity * 2;
    value_type *_new_array = _allocator.allocate(_capacity);
    for (size_type i = 0; i < _size; i++) {
        _allocator.allocate(_new_array + i, _base_array + i);
        _allocator.destroy(_base_array + i);
    }
    if (_capacity > 1)
        _allocator.deallocate(_base_array, _capacity / 2);
    _base_array = _new_array;
}

void    vector::push_back(const value_type &val) {
    if (_size == _capacity) {
        doublingCapacity();
    }
    _allocator.construct(_base_array + _size++, val);
}
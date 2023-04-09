#pragma once

#include <cstdint>
#include <cstdlib>
#include <cstring>

class Bitmap {
    public:
    uint64_t size;
    uint64_t nr_bits;
    uint64_t *data;

    Bitmap(const uint64_t nr_bits) {
        this->nr_bits = nr_bits;
        this->size = (nr_bits / 64 + 1) * sizeof(uint64_t);
        this->data= (uint64_t *)malloc(this->size);
        this->all0();
    }

    ~Bitmap() {
        free(this->data);
    }

    void set0(const uint64_t idx) {
        const uint64_t n = idx >> 6;
        const uint64_t m = idx & 0x3f;
        this->data[n] &= (~(0x1lu << m));
    }

    void set1(const uint64_t idx) {
        const uint64_t n = idx >> 6;
        const uint64_t m = idx & 0x3f;
        this->data[n] |= (0x1lu << m);
    }

    void all0() {
        memset(this->data, 0, this->size);
    }

    void all1() {
        memset(this->data, 0xff, this->size);
    }

    bool get(const uint64_t idx) {
        const uint64_t n = idx >> 6;
        const uint64_t m = idx & 0x3f;
        return (this->data[n] & (0x1lu << m));
    }
};

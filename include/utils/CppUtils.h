//
// Created by Jack Xu on 7/14/23.
//

#ifndef CEVNS_SIM_CPPUTILS_H
#define CEVNS_SIM_CPPUTILS_H

template<typename... Args>
void deleteAll(Args*... args) {
    (delete args, ...);
}

#endif //CEVNS_SIM_CPPUTILS_H

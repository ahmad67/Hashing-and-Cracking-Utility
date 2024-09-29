#include <iostream>
#include <string>
#include <openssl/sha.h>
#include <openssl/md5.h>

void hash_password(const std::string& password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)password.c_str(), password.length(), hash);

    std::cout << "SHA256 hash: ";
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    std::cout << std::endl;
}

int main() {
    std::string password;
    std::cout << "Enter a password to hash: ";
    std::cin >> password;
    
    hash_password(password);

    return 0;
}

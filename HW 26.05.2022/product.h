#ifndef HW_26_05_2022_PRODUCT_H
#define HW_26_05_2022_PRODUCT_H


#include <string>
#include <list>
#include <istream>
#include <fstream>

class product {
private:
    std::string itemName_;
    std::string itemType_;
    unsigned int itemCode_;
    unsigned int itemPrice_;
    unsigned int itemNum_;
public:
    product(const std::string& name, const std::string& type, unsigned int code, unsigned int price, unsigned int num) :
            itemName_(name), itemType_(type),
            itemCode_(code), itemPrice_(price), itemNum_(num){};
    product() = default;
    std::string getName();
    std::string getType();
    unsigned int getCode();
    unsigned int getPrice();
    unsigned int getNum();

    std::string showInString();

protected:
};

std::istream& operator>>(std::istream&, product&);
void getFileInfo(std::list<product>&,const std::string&);

#endif //HW_26_05_2022_PRODUCT_H

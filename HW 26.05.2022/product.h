#ifndef HW_26_05_2022_PRODUCT_H
#define HW_26_05_2022_PRODUCT_H

#include <string>
#include <list>
#include <istream>
#include <fstream>
#include <vector>
#include <QString>

class Product {
private:
    QString itemName_;
    QString itemType_;
    unsigned int itemCode_;
    unsigned int itemPrice_;
    unsigned int itemNum_;
public:
    Product(QString prodName,QString prodType , unsigned int prodCode, unsigned int prodPrice, unsigned int prodNum) :
            itemName_(prodName), itemType_(prodType),
            itemCode_(prodCode), itemPrice_(prodPrice), itemNum_(prodNum){};
    Product() = default;

    QString getName();
    QString getType();
    unsigned int getCode();
    unsigned int getPrice();
    unsigned int getNum();

    std::string showInString();

protected:
};

std::istream& operator>>(std::ifstream &, Product&);
void getFileInfo(std::vector<Product>&,const std::string&);

#endif //HW_26_05_2022_PRODUCT_H

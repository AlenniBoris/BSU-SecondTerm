#ifndef HW_26_05_2022_PRODUCT_H
#define HW_26_05_2022_PRODUCT_H


#include <string>
#include <list>
#include <istream>
#include <fstream>
#include <vector>
#include <QString>

class product {
private:
    QString itemName_;
    QString itemType_;
    unsigned int itemCode_;
    unsigned int itemPrice_;
    unsigned int itemNum_;
public:
    product(QString prodName,QString prodType , unsigned int prodCode, unsigned int prodPrice, unsigned int prodNum) :
            itemName_(prodName), itemType_(prodType),
            itemCode_(prodCode), itemPrice_(prodPrice), itemNum_(prodNum){};
    product() = default;

    QString getName();
    QString getType();
    unsigned int getCode();
    unsigned int getPrice();
    unsigned int getNum();

    std::string showInString();

protected:
};

std::istream& operator>>(std::ifstream &, product&);
void getFileInfo(std::vector<product>&,const std::string&);

#endif //HW_26_05_2022_PRODUCT_H

#include "product.h"

QString product::getName() {
    return itemName_;
}

QString product::getType() {
    return itemType_;
}

unsigned int product::getCode() {
    return itemCode_;
}

unsigned int product::getPrice() {
    return itemPrice_;
}

unsigned int product::getNum() {
    return itemNum_;
}

std::string product::showInString() {
    return "Имя: " + itemName_.toStdString() + "; Тип: " + itemType_.toStdString() + "; Код: " + std::to_string(itemCode_) + "; Цена: "
    + std::to_string(itemPrice_) + "; Число: " + std::to_string(itemNum_);
}

std::istream& operator>>(std::ifstream &input, product& item){
    std::string name;
    std::string type;
    unsigned int code;
    unsigned int price;
    unsigned int num;
    input >> name >> type >> code >> price >> num;

    item = product(QString::fromStdString(name), QString::fromStdString(type), code,price, num);
    return input;
}

void getFileInfo(std::vector<product>& itemList,const std::string& fileName){
    std::ifstream file(fileName);
    product temp_item;
    while(file >> temp_item){
        itemList.push_back(temp_item);
    }
}
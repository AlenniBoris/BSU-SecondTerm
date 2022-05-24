#include "product.h"

QString Product::getName() {
    return itemName_;
}

QString Product::getType() {
    return itemType_;
}

unsigned int Product::getCode() {
    return itemCode_;
}

unsigned int Product::getPrice() {
    return itemPrice_;
}

unsigned int Product::getNum() {
    return itemNum_;
}

std::string Product::showInString() {
    return "Имя: " + itemName_.toStdString() + "; Тип: " + itemType_.toStdString() + "; Код: " + std::to_string(itemCode_) + "; Цена: "
    + std::to_string(itemPrice_) + "; Число: " + std::to_string(itemNum_);
}

std::istream& operator>>(std::ifstream &input, Product& item){
    std::string name;
    std::string type;
    unsigned int code;
    unsigned int price;
    unsigned int num;
    input >> name >> type >> code >> price >> num;

    item = Product(QString::fromStdString(name), QString::fromStdString(type), code,price, num);
    return input;
}

void getFileInfo(std::vector<Product>& itemList,const std::string& fileName){
    std::ifstream file(fileName);
    Product temp_item;
    while(file >> temp_item){
        itemList.push_back(temp_item);
    }
}
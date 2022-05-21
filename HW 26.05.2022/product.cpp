#include "product.h"

std::string product::getName() {
    return itemName_;
}

std::string product::getType() {
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
    return "Имя: " + itemName_ + "; Тип: " + itemType_ + "; Код: " + std::to_string(itemCode_) + "; Цена: "
    + std::to_string(itemPrice_) + "; Число: " + std::to_string(itemNum_);
}

std::istream& operator>>(std::istream& input, product& item){
    std::string name;
    std::string type;
    unsigned int code;
    unsigned int price;
    unsigned int num;
    input >> name >> type >> code >> price >> num;
    item = product(name, type, code,price, num);
    return input;
}

void getFileInfo(std::list<product>& itemList,const std::string& fileName){
    std::ifstream file(fileName);
    product temp_item;
    while(file >> temp_item){
        itemList.push_back(temp_item);
    }
}
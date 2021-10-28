#include<iostream>
#include<string>


using namespace std;

void Chen_One();
void Chen_One_M();
//sub
void Formals();
void Dress_coat();
void T_P_Formals();
void Formal_P();
void Formal_S();
void Casual();
void C_Pant();
void C_Shirt();
void Jacket();
void Denim();
void D_Jeans();
void D_Upper();
void Shalwar_kameez();
void Shalwar_kameez_F();
void Kurta();
void Stiched();
void Un_stiched();
void Top();
void Bottom();
void Three_Piece_S();
void Three_Piece_US();
void Two_Piece_S();
void Two_Piece_US();
void T_Shirt();
void Denim_Trousers();
void Leggings();
void Trousers_Shalwar();
void Kameez();

void Chen_One_W();
//sub


void Chen_One_K();
//sub
void Chen_One_KB();
void Chen_One_KG();

void KG_Shirts();
void Girl_Pret();
void KB_Shirts();
void K_Trousers();

void Chen_One_F();
//sub
void Dining_Table();
void Sofa_Set();
void Bed();
void Dining_Table();
void Coffee_Table();

void Deduct_Products(int, int);
void Add_To_Cart(int, string, string, string, string, string);
void Check_Out();

static int counting = 0;
class Attributes {
    public:

    int price;
    string name;
    string size;
    string condition;
    string material;
    string color;
};

int price;
string name;
string size;
string condition;
string material;
string color;


Attributes Total[25];

int ch_no;
string NAME;

int main() {

    cout <<"\t\tHello There!" <<endl;
    cout <<"\t\tWELCOME TO ChenOne PAKISTAN" <<endl;
    cout <<"\t\tPlease enter your name: \n\n";
    cout <<"\t\t";
    cin >>NAME;
    cout <<"\n\n" <<endl;
    cout <<"\t\tHola " <<NAME <<"!" <<endl;
    cout <<"\t\tLet's do some Shopping \n\n" <<endl;

    Chen_One();


    return 0;
}

void Chen_One() {
    cout <<"\t\t1. ChenOne Man" <<endl;
    cout <<"\t\t2. ChenOne Women" <<endl;
    cout <<"\t\t3. ChenOne Kids" <<endl;
    cout <<"\t\t4. ChenOne Furniture" <<endl;
    cout <<"\t\t5. Back" <<endl;
    cout <<"\t\t0. Exit Program" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Chen_One_M();
            break;
            
        case 2:
            Chen_One_W();
            break;

        case 3:
            Chen_One_K();
            break;

        case 4:
            Chen_One_F();
            break;

        case 5:
            main();
            break;

        case 0:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            Chen_One();
            break;

    }
}

void Chen_One_M() {
    cout <<"\t\t1. Formal" <<endl;
    cout <<"\t\t2. Casual" <<endl;
    cout <<"\t\t3. Denim" <<endl;
    cout <<"\t\t4. Shalwaz Kameez" <<endl;
    cout <<"\t\t5. Back" <<endl;
    cout <<"\t\t0. Exit Program" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Formals();
            break;
            
        case 2:
            Casual();
            break;

        case 3:
            Denim();
            break;
        
        case 4:
            Shalwar_kameez();
            break;

        case 5:
            Chen_One();
            break;

        case 0:
            exit(1);
            break;
/*
        default:
            cout <<"Invalid Input!" <<endl;
            Chen_One_M();
            break;
*/
    }
}

void Formals() {
    cout <<"\t\t1. Dress Shirt" <<endl;
    cout <<"\t\t2. Dress pant" <<endl;
    cout <<"\t\t3. Three piece" <<endl;
    cout <<"\t\t4. Dress coat" <<endl;
    cout <<"\t\t5. Back" <<endl;
    cout <<"\t\t0. Exit Program" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Formal_S();
            break;
            
        case 2:
            Formal_P();
            break;

        case 3:
            T_P_Formals();
            break;

        case 4:
            Dress_coat();
            break;

        case 7:
            Chen_One_M();
            break;

        case 0:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            Formals();
            break;

    }
}

void Formal_S() {

    price = 2000;
    name = "Dress shirt";

    cout <<"Enter Size (S, M L & XL)";
    cin >>size;

    condition = "New";
    material = "Cotton";

    cout <<"Choose colour: " <<endl;
    cin >>color;

    back:
    cout <<"\t\tName : " <<name <<endl;
    cout <<"\t\tPrice : " <<price <<endl;
    cout <<"\t\tSize : " <<size <<endl;
    cout <<"\t\tColour : " <<color <<endl;
    cout <<"\t\tMaterial : " <<material <<endl;
    cout <<"\t\tCondition : " <<condition <<endl;

    cout <<"\t\t1. Add To Cart" <<endl;
    cout <<"\t\t2. Back" <<endl;
    cout <<"\t\t3. Check Out" <<endl;
    cout <<"\t\t4. Exit Program;" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Add_To_Cart(price, name, size, color, material, condition);
            Formals();
            break;

        case 2:
            Formals();
            break;

        case 3:
            Check_Out();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            goto back;
            break;
    }

}

void Formal_P() {

    price = 2500;
    name = "Dress pant";

    cout <<"Enter Size (S, M L & XL)";
    cin >>size;

    condition = "New";
    material = "Cotton";

    cout <<"Choose colour: " <<endl;
    cin >>color;

    back:
    cout <<"\t\tName : " <<name <<endl;
    cout <<"\t\tPrice : " <<price <<endl;
    cout <<"\t\tSize : " <<size <<endl;
    cout <<"\t\tColour : " <<color <<endl;
    cout <<"\t\tMaterial : " <<material <<endl;
    cout <<"\t\tCondition : " <<condition <<endl;

    cout <<"\t\t1. Add To Cart" <<endl;
    cout <<"\t\t2. Back" <<endl;
    cout <<"\t\t3. Check Out" <<endl;
    cout <<"\t\t4. Exit Program;" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Add_To_Cart(price, name, size, color, material, condition);
            Formals();
            break;

        case 2:
            Formals();
            break;

        case 3:
            Check_Out();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            goto back;
            break;
    }

}

void T_P_Formals() {

    price = 10000;
    name = "Three piece Formals";

    cout <<"Enter Size (S, M L & XL)";
    cin >>size;

    condition = "New";
    material = "Cotton";

    cout <<"Choose colour: " <<endl;
    cin >>color;

    back:
    cout <<"\t\tName : " <<name <<endl;
    cout <<"\t\tPrice : " <<price <<endl;
    cout <<"\t\tSize : " <<size <<endl;
    cout <<"\t\tColour : " <<color <<endl;
    cout <<"\t\tMaterial : " <<material <<endl;
    cout <<"\t\tCondition : " <<condition <<endl;

    cout <<"\t\t1. Add To Cart" <<endl;
    cout <<"\t\t2. Back" <<endl;
    cout <<"\t\t3. Check Out" <<endl;
    cout <<"\t\t4. Exit Program;" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Add_To_Cart(price, name, size, color, material, condition);
            Formals();
            break;

        case 2:
            Formals();
            break;

        case 3:
            Check_Out();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            goto back;
            break;
    }

}

void Dress_coat() {

    price = 6000;
    name = "Dress Coat";

    cout <<"Enter Size (S, M L & XL)";
    cin >>size;

    condition = "New";
    material = "Cotton";

    cout <<"Choose colour: " <<endl;
    cin >>color;

    back:
    cout <<"\t\tName : " <<name <<endl;
    cout <<"\t\tPrice : " <<price <<endl;
    cout <<"\t\tSize : " <<size <<endl;
    cout <<"\t\tColour : " <<color <<endl;
    cout <<"\t\tMaterial : " <<material <<endl;
    cout <<"\t\tCondition : " <<condition <<endl;

    cout <<"\t\t1. Add To Cart" <<endl;
    cout <<"\t\t2. Back" <<endl;
    cout <<"\t\t3. Check Out" <<endl;
    cout <<"\t\t4. Exit Program;" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Add_To_Cart(price, name, size, color, material, condition);
            Formals();
            break;

        case 2:
            Formals();
            break;

        case 3:
            Check_Out();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            goto back;
            break;
    }

}

void Casual() {
    cout <<"\t\t1. Casual Shirt" <<endl;
    cout <<"\t\t2. Casual pant" <<endl;
    cout <<"\t\t3. Jacket" <<endl;
    cout <<"\t\t4. Back" <<endl;
    cout <<"\t\t0. Exit Program" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            C_Shirt();
            break;
            
        case 2:
            C_Pant();
            break;

        case 3:
            Jacket();
            break;

        case 4:
            Chen_One_M();
            break;

        case 0:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            Casual();
            break;

    }
}
void C_Shirt() {

    price = 1200;
    name = "Casual Shirt";

    cout <<"Enter Size (S, M L & XL)";
    cin >>size;

    condition = "New";
    material = "Cotton";

    cout <<"Choose colour: " <<endl;
    cin >>color;

    back:
    cout <<"\t\tName : " <<name <<endl;
    cout <<"\t\tPrice : " <<price <<endl;
    cout <<"\t\tSize : " <<size <<endl;
    cout <<"\t\tColour : " <<color <<endl;
    cout <<"\t\tMaterial : " <<material <<endl;
    cout <<"\t\tCondition : " <<condition <<endl;

    cout <<"\t\t1. Add To Cart" <<endl;
    cout <<"\t\t2. Back" <<endl;
    cout <<"\t\t3. Check Out" <<endl;
    cout <<"\t\t4. Exit Program;" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Add_To_Cart(price, name, size, color, material, condition);
            Casual();
            break;

        case 2:
            Casual();
            break;

        case 3:
            Check_Out();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            goto back;
            break;
    }
}
void C_Pant() {

    price = 1500;
    name = "Casual Pant";

    cout <<"Enter Size (S, M L & XL)";
    cin >>size;

    condition = "New";
    material = "Cotton";

    cout <<"Choose colour: " <<endl;
    cin >>color;

    back:
    cout <<"\t\tName : " <<name <<endl;
    cout <<"\t\tPrice : " <<price <<endl;
    cout <<"\t\tSize : " <<size <<endl;
    cout <<"\t\tColour : " <<color <<endl;
    cout <<"\t\tMaterial : " <<material <<endl;
    cout <<"\t\tCondition : " <<condition <<endl;

    cout <<"\t\t1. Add To Cart" <<endl;
    cout <<"\t\t2. Back" <<endl;
    cout <<"\t\t3. Check Out" <<endl;
    cout <<"\t\t4. Exit Program;" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Add_To_Cart(price, name, size, color, material, condition);
            Casual();
            break;

        case 2:
            Casual();
            break;

        case 3:
            Check_Out();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            goto back;
            break;
    }
}
void Jacket() {

    price = 6000;
    name = "Jacket";

    cout <<"Enter Size (S, M L & XL)";
    cin >>size;

    condition = "New";
    material = "Leather";

    cout <<"Choose colour: " <<endl;
    cin >>color;

    back:
    cout <<"\t\tName : " <<name <<endl;
    cout <<"\t\tPrice : " <<price <<endl;
    cout <<"\t\tSize : " <<size <<endl;
    cout <<"\t\tColour : " <<color <<endl;
    cout <<"\t\tMaterial : " <<material <<endl;
    cout <<"\t\tCondition : " <<condition <<endl;

    cout <<"\t\t1. Add To Cart" <<endl;
    cout <<"\t\t2. Back" <<endl;
    cout <<"\t\t3. Check Out" <<endl;
    cout <<"\t\t4. Exit Program;" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Add_To_Cart(price, name, size, color, material, condition);
            Casual();
            break;

        case 2:
            Casual();
            break;

        case 3:
            Check_Out();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            goto back;
            break;
    }
}

void Denim() {
    cout <<"\t\t1. Jacket" <<endl;
    cout <<"\t\t2. Jean" <<endl;
    cout <<"\t\t3. Back" <<endl;
    cout <<"\t\t0. Exit Program" <<endl;
    cin >>ch_no;

    switch(ch_no) {
        case 1:
            D_Upper();
            break;

        case 2:
            D_Jeans();
            break;

        case 3:
            Chen_One_M();
            break;

        case 0:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            Denim();
            break;
    }
}

void D_Jeans() {
    price = 1499;
    name = "Denim Jean";

    cout <<"\t\tEnter Size (S, M L & XL)";
    cin >>size;

    condition = "New";
    material = "Denim";

    cout <<"\t\tChoose colour: ";
    cin >>color;

    back:
    cout <<"\t\tName : " <<name <<endl;
    cout <<"\t\tPrice : " <<price <<endl;
    cout <<"\t\tSize : " <<size <<endl;
    cout <<"\t\tColour : " <<color <<endl;
    cout <<"\t\tMaterial : " <<material <<endl;
    cout <<"\t\tCondition : " <<condition <<endl;

    cout <<"\t\t1. Add To Cart" <<endl;
    cout <<"\t\t2. Back" <<endl;
    cout <<"\t\t3. Check Out" <<endl;
    cout <<"\t\t4. Exit Program;" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Add_To_Cart(price, name, size, color, material, condition);
            Denim();
            break;

        case 2:
            Denim();
            break;

        case 3:
            Check_Out();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            goto back;
            break;
    }
}

void D_Upper() {
    price = 4129;
    name = "Denim Upper";

    cout <<"\t\tEnter Size (S, M L & XL)";
    cin >>size;

    condition = "New";
    material = "Denim";

    cout <<"\t\tChoose colour: ";
    cin >>color;

    back:
    cout <<"\t\tName : " <<name <<endl;
    cout <<"\t\tPrice : " <<price <<endl;
    cout <<"\t\tSize : " <<size <<endl;
    cout <<"\t\tColour : " <<color <<endl;
    cout <<"\t\tMaterial : " <<material <<endl;
    cout <<"\t\tCondition : " <<condition <<endl;

    cout <<"\t\t1. Add To Cart" <<endl;
    cout <<"\t\t2. Back" <<endl;
    cout <<"\t\t3. Check Out" <<endl;
    cout <<"\t\t4. Exit Program;" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Add_To_Cart(price, name, size, color, material, condition);
            Denim();
            break;

        case 2:
            Denim();
            break;

        case 3:
            Check_Out();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            goto back;
            break;
    }
}

void Shalwar_kameez() {
    cout <<"\t\t1. Shalwar Kameez" <<endl;
    cout <<"\t\t2. Kurta" <<endl;
    cout <<"\t\t3. Back" <<endl;
    cout <<"\t\t0. Exit Program" <<endl;
    cin >>ch_no;

    switch(ch_no) {
        case 1:
            Shalwar_kameez_F();
            break;

        case 2:
            Kurta();
            break;

        case 3:
            Chen_One_M();
            break;

        case 0:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            Shalwar_kameez();
            break;
    }
}

void Shalwar_kameez_F() {
    price = 4500;
    name = "Shalwar Kameez";

    cout <<"\t\tEnter Size (S, M L & XL)";
    cin >>size;

    condition = "New";
    material = "COTTON SATIN STUFF";

    cout <<"\t\tChoose colour: ";
    cin >>color;

    back:
    cout <<"\t\tName : " <<name <<endl;
    cout <<"\t\tPrice : " <<price <<endl;
    cout <<"\t\tSize : " <<size <<endl;
    cout <<"\t\tColour : " <<color <<endl;
    cout <<"\t\tMaterial : " <<material <<endl;
    cout <<"\t\tCondition : " <<condition <<endl;

    cout <<"\t\t1. Add To Cart" <<endl;
    cout <<"\t\t2. Back" <<endl;
    cout <<"\t\t3. Check Out" <<endl;
    cout <<"\t\t4. Exit Program;" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Add_To_Cart(price, name, size, color, material, condition);
            Shalwar_kameez();
            break;

        case 2:
            Shalwar_kameez();
            break;

        case 3:
            Check_Out();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            goto back;
            break;
    }
}

void Kurta() {
    price = 2600;
    name = "Kurta";

    cout <<"\t\tEnter Size (S, M L & XL)";
    cin >>size;

    condition = "New";
    material = "COTTON SATIN STUFF";

    cout <<"\t\tChoose colour: ";
    cin >>color;

    back:
    cout <<"\t\tName : " <<name <<endl;
    cout <<"\t\tPrice : " <<price <<endl;
    cout <<"\t\tSize : " <<size <<endl;
    cout <<"\t\tColour : " <<color <<endl;
    cout <<"\t\tMaterial : " <<material <<endl;
    cout <<"\t\tCondition : " <<condition <<endl;

    cout <<"\t\t1. Add To Cart" <<endl;
    cout <<"\t\t2. Back" <<endl;
    cout <<"\t\t3. Check Out" <<endl;
    cout <<"\t\t4. Exit Program;" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Add_To_Cart(price, name, size, color, material, condition);
            Shalwar_kameez();
            break;

        case 2:
            Shalwar_kameez();
            break;

        case 3:
            Check_Out();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            goto back;
            break;
    }
}

void Chen_One_W() {
    cout <<"\t\t1. Stiched" <<endl;
    cout <<"\t\t2. Unstiched" <<endl;
    cout <<"\t\t3. Top" <<endl;
    cout <<"\t\t4. Bottom" <<endl;
    cout <<"\t\t5. Back" <<endl;
    cout <<"\t\t0. Exit Program" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Stiched();
            break;
        
        case 2:
            Un_stiched();
            break;

        case 3:
            Top();
            break;
        
        case 4:
            Bottom();
            break;

        case 5:
            Chen_One();
            break;

        case 0:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            Chen_One_W();
            break;

    }
}

void Stiched() {
    cout <<"\t\t1. 3-Piece" <<endl;
    cout <<"\t\t2. 2_piece" <<endl;
    cout <<"\t\t3. Back" <<endl;
    cout <<"\t\t0. Exit Program" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Three_Piece_S();
            break;
        
        case 2:
            Two_Piece_S();
            break;

        case 3:
            Chen_One_W();
            break;

        case 0:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            Stiched();
            break;

    }
}
void Un_stiched() {
    cout <<"\t\t1. 3-Piece" <<endl;
    cout <<"\t\t2. 2-piece" <<endl;
    cout <<"\t\t3. Back" <<endl;
    cout <<"\t\t0. Exit Program" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Three_Piece_US();
            break;

        case 2:
            Two_Piece_US();
            break;

        case 3:
            Chen_One_W();
            break;

        case 0:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            Un_stiched();
            break;

    }
}

void Top() {
    cout <<"\t\t1. Shirt" <<endl;
    cout <<"\t\t2. Kameez" <<endl;
    cout <<"\t\t3. Back" <<endl;
    cout <<"\t\t0. Exit Program" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            T_Shirt();
            break;
            
        case 2:
            Two_Piece_US();
            break;

        case 3:
            Chen_One_W();
            break;

        case 0:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            Top();
            break;

    }
}
void T_Shirt() {

    price = 1799;
    name = "T shirt";

    cout <<"\t\tEnter Size (S, M L & XL)";
    cin >>size;

    condition = "New";
    material = "COTTON";

    cout <<"\t\tChoose colour: ";
    cin >>color;

    back:
    cout <<"\t\tName : " <<name <<endl;
    cout <<"\t\tPrice : " <<price <<endl;
    cout <<"\t\tSize : " <<size <<endl;
    cout <<"\t\tColour : " <<color <<endl;
    cout <<"\t\tMaterial : " <<material <<endl;
    cout <<"\t\tCondition : " <<condition <<endl;

    cout <<"\t\t1. Add To Cart" <<endl;
    cout <<"\t\t2. Back" <<endl;
    cout <<"\t\t3. Check Out" <<endl;
    cout <<"\t\t4. Exit Program;" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Add_To_Cart(price, name, size, color, material, condition);
            Top();
            break;

        case 2:
            Top();
            break;

        case 3:
            Check_Out();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            goto back;
            break;
    }
}

void Kameez() {

    price = 3000;
    name = "Kameez";

    cout <<"\t\tEnter Size (S, M L & XL)";
    cin >>size;

    condition = "New";
    material = "COTTON";

    cout <<"\t\tChoose colour: ";
    cin >>color;

    back:
    cout <<"\t\tName : " <<name <<endl;
    cout <<"\t\tPrice : " <<price <<endl;
    cout <<"\t\tSize : " <<size <<endl;
    cout <<"\t\tColour : " <<color <<endl;
    cout <<"\t\tMaterial : " <<material <<endl;
    cout <<"\t\tCondition : " <<condition <<endl;

    cout <<"\t\t1. Add To Cart" <<endl;
    cout <<"\t\t2. Back" <<endl;
    cout <<"\t\t3. Check Out" <<endl;
    cout <<"\t\t4. Exit Program;" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Add_To_Cart(price, name, size, color, material, condition);
            Top();
            break;

        case 2:
            Top();
            break;

        case 3:
            Check_Out();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            goto back;
            break;
    }
}

void Bottom() {
    cout <<"\t\t1. Denim Trousers" <<endl;
    cout <<"\t\t2. Jean" <<endl;
    cout <<"\t\t3. Leggings" <<endl;
    cout <<"\t\t4. Back" <<endl;
    cout <<"\t\t0. Exit Program" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Denim_Trousers();
            break;
            
        case 2:
            Trousers_Shalwar();
            break;

        case 3:
            Leggings();
            break;

        case 4:
            Chen_One_W();
            break;

        case 0:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            Bottom();
            break;

    }
}

void Denim_Trousers() {

    price = 2250;
    name = "Denim Trousers";

    cout <<"\t\tEnter Size (S, M L & XL)";
    cin >>size;

    condition = "New";
    material = "Denim";

    cout <<"\t\tChoose colour: ";
    cin >>color;

    back:
    cout <<"\t\tName : " <<name <<endl;
    cout <<"\t\tPrice : " <<price <<endl;
    cout <<"\t\tSize : " <<size <<endl;
    cout <<"\t\tColour : " <<color <<endl;
    cout <<"\t\tMaterial : " <<material <<endl;
    cout <<"\t\tCondition : " <<condition <<endl;

    cout <<"\t\t1. Add To Cart" <<endl;
    cout <<"\t\t2. Back" <<endl;
    cout <<"\t\t3. Check Out" <<endl;
    cout <<"\t\t4. Exit Program;" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Add_To_Cart(price, name, size, color, material, condition);
            Bottom();
            break;

        case 2:
            Bottom();
            break;

        case 3:
            Check_Out();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            goto back;
            break;
    }
}

void Trousers_Shalwar() {

    cout <<"\t\t1. Trouser" <<endl;
    cout <<"\t\t2. Shalwar" <<endl;
    cin >>ch_no;

    if (ch_no == 1) {
        price = 1950;
        name = "Trouser";
    } else if(ch_no == 2) {
        price = 1550;
        name = "Shalwar";
    } else {
        cout <<"Invalid Input" <<endl;
        Trousers_Shalwar();
    }
    

    cout <<"\t\tEnter Size (S, M L & XL)";
    cin >>size;

    condition = "New";
    material = "Cotton";

    cout <<"\t\tChoose colour: ";
    cin >>color;

    back:
    cout <<"\t\tName : " <<name <<endl;
    cout <<"\t\tPrice : " <<price <<endl;
    cout <<"\t\tSize : " <<size <<endl;
    cout <<"\t\tColour : " <<color <<endl;
    cout <<"\t\tMaterial : " <<material <<endl;
    cout <<"\t\tCondition : " <<condition <<endl;

    cout <<"\t\t1. Add To Cart" <<endl;
    cout <<"\t\t2. Back" <<endl;
    cout <<"\t\t3. Check Out" <<endl;
    cout <<"\t\t4. Exit Program;" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Add_To_Cart(price, name, size, color, material, condition);
            Bottom();
            break;

        case 2:
            Bottom();
            break;

        case 3:
            Check_Out();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            goto back;
            break;
    }
}

void Leggings() {

    price = 1350;
    name = "Leggings";

    cout <<"\t\tEnter Size (S, M L & XL)";
    cin >>size;

    condition = "New";
    material = "COTTON LYCRA STUFF";

    cout <<"\t\tChoose colour: ";
    cin >>color;

    back:
    cout <<"\t\tName : " <<name <<endl;
    cout <<"\t\tPrice : " <<price <<endl;
    cout <<"\t\tSize : " <<size <<endl;
    cout <<"\t\tColour : " <<color <<endl;
    cout <<"\t\tMaterial : " <<material <<endl;
    cout <<"\t\tCondition : " <<condition <<endl;

    cout <<"\t\t1. Add To Cart" <<endl;
    cout <<"\t\t2. Back" <<endl;
    cout <<"\t\t3. Check Out" <<endl;
    cout <<"\t\t4. Exit Program;" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Add_To_Cart(price, name, size, color, material, condition);
            Bottom();
            break;

        case 2:
            Bottom();
            break;

        case 3:
            Check_Out();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            goto back;
            break;
    }

}


void Three_Piece_US() {

    price = 4000;
    name = "Unstiched Three piece";

    cout <<"\t\tEnter Size (S, M L & XL)";
    cin >>size;

    condition = "New";
    material = "COTTON";

    cout <<"\t\tChoose colour: ";
    cin >>color;

    back:
    cout <<"\t\tName : " <<name <<endl;
    cout <<"\t\tPrice : " <<price <<endl;
    cout <<"\t\tSize : " <<size <<endl;
    cout <<"\t\tColour : " <<color <<endl;
    cout <<"\t\tMaterial : " <<material <<endl;
    cout <<"\t\tCondition : " <<condition <<endl;

    cout <<"\t\t1. Add To Cart" <<endl;
    cout <<"\t\t2. Back" <<endl;
    cout <<"\t\t3. Check Out" <<endl;
    cout <<"\t\t4. Exit Program;" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Add_To_Cart(price, name, size, color, material, condition);
            Un_stiched();
            break;

        case 2:
            Un_stiched();
            break;

        case 3:
            Check_Out();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            goto back;
            break;
    }

}

void Two_Piece_US() {

    price = 3000;
    name = "Unstiched Two piece";

    cout <<"\t\tEnter Size (S, M L & XL)";
    cin >>size;

    condition = "New";
    material = "COTTON";

    cout <<"\t\tChoose colour: ";
    cin >>color;

    back:
    cout <<"\t\tName : " <<name <<endl;
    cout <<"\t\tPrice : " <<price <<endl;
    cout <<"\t\tSize : " <<size <<endl;
    cout <<"\t\tColour : " <<color <<endl;
    cout <<"\t\tMaterial : " <<material <<endl;
    cout <<"\t\tCondition : " <<condition <<endl;

    cout <<"\t\t1. Add To Cart" <<endl;
    cout <<"\t\t2. Back" <<endl;
    cout <<"\t\t3. Check Out" <<endl;
    cout <<"\t\t4. Exit Program;" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Add_To_Cart(price, name, size, color, material, condition);
            Un_stiched();
            break;

        case 2:
            Un_stiched();
            break;

        case 3:
            Check_Out();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            goto back;
            break;
    }
}

void Two_Piece_S() {

    price = 4000;
    name = "stiched Two piece";

    cout <<"\t\tEnter Size (S, M L & XL)";
    cin >>size;

    condition = "New";
    material = "COTTON";

    cout <<"\t\tChoose colour: ";
    cin >>color;

    back:
    cout <<"\t\tName : " <<name <<endl;
    cout <<"\t\tPrice : " <<price <<endl;
    cout <<"\t\tSize : " <<size <<endl;
    cout <<"\t\tColour : " <<color <<endl;
    cout <<"\t\tMaterial : " <<material <<endl;
    cout <<"\t\tCondition : " <<condition <<endl;

    cout <<"\t\t1. Add To Cart" <<endl;
    cout <<"\t\t2. Back" <<endl;
    cout <<"\t\t3. Check Out" <<endl;
    cout <<"\t\t4. Exit Program;"  <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Add_To_Cart(price, name, size, color, material, condition);
            Stiched();
            break;

        case 2:
            Stiched();
            break;

        case 3:
            Check_Out();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            goto back;
            break;
    }
}
void Three_Piece_S() {

    price = 5000;
    name = "stiched Three piece";

    cout <<"\t\tEnter Size (S, M L & XL)";
    cin >>size;

    condition = "New";
    material = "COTTON";

    cout <<"\t\tChoose colour: ";
    cin >>color;

    back:
    cout <<"\t\tName : " <<name <<endl;
    cout <<"\t\tPrice : " <<price <<endl;
    cout <<"\t\tSize : " <<size <<endl;
    cout <<"\t\tColour : " <<color <<endl;
    cout <<"\t\tMaterial : " <<material <<endl;
    cout <<"\t\tCondition : " <<condition <<endl;

    cout <<"\t\t1. Add To Cart" <<endl;
    cout <<"\t\t2. Back" <<endl;
    cout <<"\t\t3. Check Out" <<endl;
    cout <<"\t\t4. Exit Program;" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Add_To_Cart(price, name, size, color, material, condition);
            Stiched();
            break;

        case 2:
            Stiched();
            break;

        case 3:
            Check_Out();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            goto back;
            break;
    }
}

void Chen_One_K() {

    cout <<"\t\t1. Boys" <<endl;
    cout <<"\t\t2. Girls" <<endl;
    cout <<"\t\t3. Back" <<endl;
    cout <<"\t\t0. Exit Program" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Chen_One_KB();
            break;
            
        case 2:
            Chen_One_KG();
            break;

        case 3:
            Chen_One();
            break;

        case 0:
            exit(1);
            break;

        default:
            cout <<"\t\tInvalid Input!" <<endl;
            Chen_One_K();
            break;

    }
    
}
void Chen_One_KB() {
    cout <<"\t\t1. Trousers" <<endl;
    cout <<"\t\t2. Shirts" <<endl;
    cout <<"\t\t3. Back" <<endl;
    cout <<"\t\t0. Exit Program" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            K_Trousers();
            break;
            
        case 2:
            KB_Shirts();
            break;

        case 3:
            Chen_One_K();
            break;

        case 0:
            exit(1);
            break;

        default:
            cout <<"\t\tInvalid Input!" <<endl;
            Chen_One_KB();
            break;

    }
}

void K_Trousers() {
    cout <<"\t\t1. Denim" <<endl;
    cout <<"\t\t2. Pull on" <<endl;
    cin >>ch_no;

    if (ch_no == 1) {
        price = 1679;
        name = "\t\tDenim Trouser";    
        material = "\t\tDenim";
    } else if (ch_no == 2) {
        price = 1049;
        name = "\t\tPull on Trouser";    
        material = "\t\tTwill Stuff";
    } else {
        cout <<"\t\tInvalid Input!"<<endl;
        K_Trousers();
    }


    cout <<"\t\tEnter Size (S, M L & XL)";
    cin >>size;
    

    cout <<"\t\tChoose colour: ";
    cin >>color;

    back:
    cout <<"\t\tName : " <<name <<endl;
    cout <<"\t\tPrice : " <<price <<endl;
    cout <<"\t\tSize : " <<size <<endl;
    cout <<"\t\tColour : " <<color <<endl;
    cout <<"\t\tMaterial : " <<material <<endl;
    cout <<"\t\tCondition : " <<condition <<endl;

    cout <<"\t\t1. Add To Cart" <<endl;
    cout <<"\t\t2. Back" <<endl;
    cout <<"\t\t3. Check Out" <<endl;
    cout <<"\t\t4. Exit Program;" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Add_To_Cart(price, name, size, color, material, condition);
            Chen_One_KB();
            break;

        case 2:
            Chen_One_KB();
            break;

        case 3:
            Check_Out();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            goto back;
            break;
    }
}

void KB_Shirts() {
    price = 999;
    name = "Kids Shirt\t";

    cout <<"\t\tEnter Size (S, M L & XL)";
    cin >>size;

    condition = "New";
    material = "COTTON";

    cout <<"\t\tChoose colour: ";
    cin >>color;

    back:
    cout <<"\t\tName : " <<name <<endl;
    cout <<"\t\tPrice : " <<price <<endl;
    cout <<"\t\tSize : " <<size <<endl;
    cout <<"\t\tColour : " <<color <<endl;
    cout <<"\t\tMaterial : " <<material <<endl;
    cout <<"\t\tCondition : " <<condition <<endl;

    cout <<"\t\t1. Add To Cart" <<endl;
    cout <<"\t\t2. Back" <<endl;
    cout <<"\t\t3. Check Out" <<endl;
    cout <<"\t\t4. Exit Program;" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Add_To_Cart(price, name, size, color, material, condition);
            Chen_One_KB();
            break;

        case 2:
            Chen_One_KB();
            break;

        case 3:
            Check_Out();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            goto back;
            break;
    }
}

void Chen_One_KG() {
    cout <<"\t\t1. Girl Pret" <<endl;
    cout <<"\t\t2. Shirt" <<endl;
    cout <<"\t\t3. Back" <<endl;
    cout <<"\t\t0. Exit Program" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Girl_Pret();
            break;
            
        case 2:
            KG_Shirts();
            break;

        case 3:
            Chen_One_K();
            break;

        case 0:
            exit(1);
            break;

        default:
            cout <<"\t\tInvalid Input!" <<endl;
            Chen_One_KG();
            break;

    }
}

void Girl_Pret() {
    price = 1999;
    name = "Girl Pret";

    cout <<"\t\tEnter Size (S, M L & XL)";
    cin >>size;

    condition = "New";
    material = "COTTON";

    cout <<"\t\tChoose colour: ";
    cin >>color;

    back:
    cout <<"\t\tName : " <<name <<endl;
    cout <<"\t\tPrice : " <<price <<endl;
    cout <<"\t\tSize : " <<size <<endl;
    cout <<"\t\tColour : " <<color <<endl;
    cout <<"\t\tMaterial : " <<material <<endl;
    cout <<"\t\tCondition : " <<condition <<endl;

    cout <<"\t\t1. Add To Cart" <<endl;
    cout <<"\t\t2. Back" <<endl;
    cout <<"\t\t3. Check Out" <<endl;
    cout <<"\t\t4. Exit Program;" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Add_To_Cart(price, name, size, color, material, condition);
            Chen_One_KG();
            break;

        case 2:
            Chen_One_KG();
            break;

        case 3:
            Check_Out();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            goto back;
            break;
    }
}
void KG_Shirts() {
    price = 1500;
    name = "Girl Shirt";

    cout <<"\t\tEnter Size (S, M L & XL)";
    cin >>size;

    condition = "New";
    material = "COTTON";

    cout <<"\t\tChoose colour: ";
    cin >>color;

    back:
    cout <<"\t\tName : " <<name <<endl;
    cout <<"\t\tPrice : " <<price <<endl;
    cout <<"\t\tSize : " <<size <<endl;
    cout <<"\t\tColour : " <<color <<endl;
    cout <<"\t\tMaterial : " <<material <<endl;
    cout <<"\t\tCondition : " <<condition <<endl;

    cout <<"\t\t1. Add To Cart" <<endl;
    cout <<"\t\t2. Back" <<endl;
    cout <<"\t\t3. Check Out" <<endl;
    cout <<"\t\t4. Exit Program;" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Add_To_Cart(price, name, size, color, material, condition);
            Chen_One_KG();
            break;

        case 2:
            Chen_One_KG();
            break;

        case 3:
            Check_Out();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            goto back;
            break;
    }
}

void Chen_One_F() {
    cout <<"\t\t1. Coffee Table" <<endl;
    cout <<"\t\t2. Bed" <<endl;
    cout <<"\t\t3. Sofa Set" <<endl;
    cout <<"\t\t4. Dining Table" <<endl;
    cout <<"\t\t5. Back" <<endl;
    cout <<"\t\t0. Exit Program" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Coffee_Table();
            break;
            
        case 2:
            Bed();
            break;

        case 3:
            Sofa_Set();
            break;

        case 4:
            Dining_Table();
            break;

        case 5:
            Chen_One();
            break;

        case 0:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            Chen_One_F();
            break;

    }
}
void Coffee_Table() {
    price = 80000;
    name = "Coffee Table";

    size = "Regular";

    condition = "New";
    material = "Wood";

    color = "Brown";

    back:
    cout <<"\t\tName : " <<name <<endl;
    cout <<"\t\tPrice : " <<price <<endl;
    cout <<"\t\tSize : " <<size <<endl;
    cout <<"\t\tColour : " <<color <<endl;
    cout <<"\t\tMaterial : " <<material <<endl;
    cout <<"\t\tCondition : " <<condition <<endl;

    cout <<"\t\t1. Add To Cart" <<endl;
    cout <<"\t\t2. Back" <<endl;
    cout <<"\t\t3. Check Out" <<endl;
    cout <<"\t\t4. Exit Program;" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Add_To_Cart(price, name, size, color, material, condition);
            Chen_One_F();
            break;

        case 2:
            Chen_One_F();
            break;

        case 3:
            Check_Out();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            goto back;
            break;
    }
}
void Bed() {
    price = 100000;
    name = "Bed\t";

    size = "King";

    condition = "New";
    material = "Wood";

    color = "Brown";

    back:
    cout <<"\t\tName : " <<name <<endl;
    cout <<"\t\tPrice : " <<price <<endl;
    cout <<"\t\tSize : " <<size <<endl;
    cout <<"\t\tColour : " <<color <<endl;
    cout <<"\t\tMaterial : " <<material <<endl;
    cout <<"\t\tCondition : " <<condition <<endl;

    cout <<"\t\t1. Add To Cart" <<endl;
    cout <<"\t\t2. Back" <<endl;
    cout <<"\t\t3. Check Out" <<endl;
    cout <<"\t\t4. Exit Program;" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Add_To_Cart(price, name, size, color, material, condition);
            Chen_One_F();
            break;

        case 2:
            Chen_One_F();
            break;

        case 3:
            Check_Out();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            goto back;
            break;
    }
}
void Sofa_Set() {
    price = 250000;
    name = "Sofa Set";

    size = "Regular";

    condition = "New";
    material = "Wood";

    color = "Brown";

    back:
    cout <<"\t\tName : " <<name <<endl;
    cout <<"\t\tPrice : " <<price <<endl;
    cout <<"\t\tSize : " <<size <<endl;
    cout <<"\t\tColour : " <<color <<endl;
    cout <<"\t\tMaterial : " <<material <<endl;
    cout <<"\t\tCondition : " <<condition <<endl;

    cout <<"\t\t1. Add To Cart" <<endl;
    cout <<"\t\t2. Back" <<endl;
    cout <<"\t\t3. Check Out" <<endl;
    cout <<"\t\t4. Exit Program;" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Add_To_Cart(price, name, size, color, material, condition);
            Chen_One_F();
            break;

        case 2:
            Chen_One_F();
            break;

        case 3:
            Check_Out();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            goto back;
            break;
    }

    
}
void Dining_Table() {
    price = 349999;
    name = "Dining Table";

    size = "Regular";

    condition = "New";
    material = "Wood";

    color = "Brown";

    back:
    cout <<"\t\tName : " <<name <<endl;
    cout <<"\t\tPrice : " <<price <<endl;
    cout <<"\t\tSize : " <<size <<endl;
    cout <<"\t\tColour : " <<color <<endl;
    cout <<"\t\tMaterial : " <<material <<endl;
    cout <<"\t\tCondition : " <<condition <<endl;

    cout <<"\t\t1. Add To Cart" <<endl;
    cout <<"\t\t2. Back" <<endl;
    cout <<"\t\t3. Check Out" <<endl;
    cout <<"\t\t4. Exit Program;" <<endl;
    cin >>ch_no;

    switch (ch_no) {
        case 1:
            Add_To_Cart(price, name, size, color, material, condition);
            Chen_One_F();
            break;

        case 2:
            Chen_One_F();
            break;

        case 3:
            Check_Out();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout <<"Invalid Input!" <<endl;
            goto back;
            break;
    }
}

void Add_To_Cart(int a, string b, string c, string d, string e, string f) {
    Total[counting].price = a;
    Total[counting].name = b;
    Total[counting].size = c;
    Total[counting].color = d;
    Total[counting].material = e;
    Total[counting].condition = f;

    cout <<"\t\tAdded to cart" <<endl;
    counting++;
}
void Check_Out() {

    int sum = 0, i, bill, remain;
    cout <<"\t Serial No.    Name   \tSize \tColour  \tMaterial   \tCondition \t Price\n\n" <<endl;
    for (i=0 ; i<counting ; i++) {
        cout <<"\t "  << i+1 <<"   " <<Total[i].name <<"    " <<Total[i].size <<" \t" <<Total[i].color <<"  \t\t" <<Total[i].material <<"      \t" <<Total[i].condition 
        <<" \t " <<Total[i].price <<endl;
    }

    for (i=0 ; i<counting ; i++) {
        sum += Total[i].price;
    }

    cout <<"\n\n" <<endl;
    cout <<"\t\tTotal Bill = "  <<sum <<"\n" <<endl;
    cout <<"\t\t Pay Amount " <<endl;
    cout <<"\t\t";
    cin >>bill;

    if ((sum-bill) == 0) {
        cout <<"\t\tYou Have Paid " <<bill <<endl;
        cout <<"\t\tTHANK YOU FOR SHOPPING!" <<endl;

    } else if ((sum-bill) < 0) {
        cout <<"\t\tYou Have Paid " <<bill <<endl;
        cout <<"\t\t Here's Your Change: " <<bill-sum <<endl;
        cout <<"\t\tTHANK YOU FOR SHOPPING!" <<endl;

    } else {
        back:
        cout <<"\t\tYou Have Paid " <<bill <<endl;
        cout <<"\t\tYou need to pay " <<sum-bill <<" more\n\n" <<endl;
        cout <<"\t\t1. Pay Now" <<endl;
        cout <<"\t\t2. Deduct products" <<endl;
        cout <<"\t\t3. Cancel Shopping" <<endl;
        cin >>ch_no;
        
        remain = sum-bill;
        switch (ch_no) {
            case 1:
                cout <<"\t\tRemaing Cash: " <<remain <<endl;
                cout <<"Pay: " <<endl;
                cin >>bill;

                if (bill < remain) {
                    cout <<"\t\tYou couldn't Pay!" <<endl;
                    cout <<"\t\tYou can't Buy" <<endl;
                    cout <<"Good Bye";
                    exit(1);

                } else if (bill > remain){
                    cout <<"\t\tYou Have Paid " <<bill <<endl;
                    cout <<"\t\t Here's Your Change: " <<bill-remain <<endl;
                    cout <<"\t\tTHANK YOU FOR SHOPPING!" <<endl;

                } else {
                    cout <<"\t\tYou Have Paid " <<bill <<endl;
                    cout <<"\t\tTHANK YOU FOR SHOPPING!" <<endl;
                }

            case 2:
                Deduct_Products(sum, bill);
                break;

            case 3:
                exit(1);
                break;

            default:
                cout <<"Invalid Input!" <<endl;
                goto back;
        }

    }

}
void Deduct_Products(int tot, int paid) {
    int sum, i, remain;
    cout <<"\t Serial No.    Name   \tSize \tColour  \tMaterial   \tCondition \t Price\n\n" <<endl;

    for (i=0 ; i<counting ; i++) {
        cout <<"\t " << i+1 <<"    " <<Total[i].name <<"  \t" <<Total[i].size <<" \t" <<Total[i].color <<"  \t" <<Total[i].material <<"  \t" 
        <<Total[i].condition <<" \t " <<Total[i].price <<"\n\n" <<endl;
    }

    cout <<"\tSelect Serial Number of the Product You want to remove\n\n" <<endl;
    cout <<"\t\t";
    cin >>ch_no;

    counting--;
    for (i=ch_no-1 ; i<counting ; i++) {
        Total[i].price = Total[i+1].price;
        Total[i].size = Total[i+1].size;
        Total[i].color = Total[i+1].color;
        Total[i].material = Total[i+1].material;
        Total[i].condition = Total[i].condition;
    }

    cout <<"\n\n\t\t " <<Total[ch_no-1].name <<" is Removed From The cart!" <<endl;

    for (i=0 ; i<counting ; i++) {
        sum += Total[i].price;
    }

    cout <<"\t Serial No.   tName   \tSize \tColour  \tMaterial   \tCondition \t Price" <<endl;

    for (i=0 ; i<counting ; i++) {
        cout <<"\t\t"  << i+1 <<"    " <<Total[i].name <<"  \t" <<Total[i].size <<" \t" <<Total[i].color <<"  \t" <<Total[i].material <<"  \t" 
        <<Total[i].condition <<" \t " <<Total[i].price <<endl;
    }

    cout <<"\n\n\t\tTotal Bill = "  <<sum <<"\n" <<endl;

    remain = sum-paid;

    if (paid >= sum) {
        cout <<"\t\tYou Have Paid " <<paid <<endl;
        cout <<"\t\tHere's Your Change: " <<remain <<endl;
        cout <<"\t\tTHANK YOU FOR SHOPPING!" <<endl;

    } else {
        cout <<"\t\tYou still have to pay" <<remain <<"more" <<endl;
        cout <<"\t\t1. Deduct more" <<endl;
        cout <<"\t\t2. Cancel Shopping" <<endl;
        cin >>ch_no;

        switch (ch_no) {
            case 1:
                Deduct_Products(tot, paid);
                break;

            case 2:
                exit(1);
                break;
        }
    }
}

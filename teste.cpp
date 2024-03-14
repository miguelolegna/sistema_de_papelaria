#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // Para std::setw

using namespace std;

// Definição da estrutura de produto
struct Product {
    string name;
    double purchasePrice;
    double salePrice;
    double profit;
};

// Função para adicionar um novo produto ao vetor de produtos
void addProduct(vector<Product>& products) {
    Product newProduct;
    cout << "Digite o nome do produto: ";
    cin >> newProduct.name;
    cout << "Digite o preco de compra do produto: ";
    cin >> newProduct.purchasePrice;
    cout << "Digite o preco de venda do produto: ";
    cin >> newProduct.salePrice;
    newProduct.profit = newProduct.salePrice - newProduct.purchasePrice;
    products.push_back(newProduct);
    cout << "Produto adicionado com sucesso!\n";
}

// tabela para exibir os produtos e lucros

void displayProducts(const vector<Product>& products) {
    if (products.empty()) {
        cout << "Não existem itens.\n";
    } else {
        cout << "Produtos:\n";
        cout << left << setw(20) << "Nome" << setw(15) << "Preco de compra   " << setw(15) << "Preco de venda" << setw(10) << "Lucro" << endl;
        cout << setfill('-') << setw(60) << "-" << endl;
        cout << setfill(' ');
        for (const auto& product : products) {
            cout << left << setw(20) << product.name << setw(15) << product.purchasePrice
                 << setw(15) << product.salePrice << setw(10) << product.profit << endl;
        }
    }
}


int main() {
    vector<Product> products; // Vetor para armazenar os produtos

    int choice;
    do {
        cout << "\nEscolha uma opcao:\n"
             << "1. Mostrar esta lista\n"
             << "2. Adicionar produto\n"
             << "3. Exibir produtos e lucros\n"
             << "4. Sair\n"
             << "Sua opcao: ";
        cin >> choice;

        switch (choice) {
            case 2:
                addProduct(products);
                break;
            case 3:
                displayProducts(products);
                break;
            case 4:
                cout << "Adeus...";
                break;
            default:
                cout << " Opção inválida. Tente novamente.";
        }
    } while (choice != 4);

    return 0;
}

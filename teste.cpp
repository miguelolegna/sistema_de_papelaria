#include <iostream>
#include <vector>
#include <string>
#include <iomanip> 
#include <algorithm>
#include <unistd.h>

using namespace std;


// definição da estrutura de produto
struct Product {
    int id;
    string name;
    double purchasePrice;
    double salePrice;
    double profit;
    int stock;
};

// Variável global para armazenar o último ID atribuído
int lastProductId = 4;

// Incrementa o ID para o novo produto
void addProduct(vector<Product>& products) {
    Product newProduct;
    
    lastProductId++;
    
    cout << "\nDigite o nome do produto: ";
    cin >> newProduct.name;
    cout << "Digite o preco de compra do produto: ";
    cin >> newProduct.purchasePrice;
    cout << "Digite o preco de venda do produto: ";
    cin >> newProduct.salePrice;
    newProduct.profit = newProduct.salePrice - newProduct.purchasePrice;
    cout << "Digite a quantidade a comprar: ";
    cin >> newProduct.stock;
    
    // Atribui o ID atual ao novo produto
    newProduct.id = lastProductId;
    
    // Adiciona o novo produto ao vetor
    products.push_back(newProduct);
    
    cout << "Produto adicionado com sucesso!\n";
}

// tabela para exibir os produtos 

void displayProducts(const vector<Product>& products) {
    if (products.empty()) {
        cout << "\nNão existem itens.\n";
    } else {
        cout << "\nTabela de produtos:\n\n";
        cout << left << setw(5) << "Id" << setw(20) << "Nome" << setw(20) << "Preco de compra" << setw(20) << "Preco de venda" << setw(15) << "Lucro" << setw(10) << "Estoque" << endl;
        cout << setfill('-') << setw(85) << "-" << endl;
        cout << setfill(' ');
        for (const auto& product : products) {
            cout << setw(5) << left << product.id << setw(20) << product.name << setw(20) << fixed << setprecision(2) << product.purchasePrice
                 << setw(20) << fixed << setprecision(2) << product.salePrice << setw(15) << fixed << setprecision(2) << product.profit
                 << setw(10) << product.stock << endl;
        }
    }
}


// função para comprar um produto
void buyProduct(vector<Product>& products) {
    int id;
    int quantity;
    cout << "\nDigite o ID do produto que deseja comprar: ";
    cin >> id;
    cout << "Digite a quantidade que deseja comprar: ";
    cin >> quantity;


    // Procura o produto pelo ID
    auto it = find_if(products.begin(), products.end(), [id](const Product& p) {
    return p.id == id;
    });


    // Verifica se o produto foi encontrado
    if (it != products.end()) {
        it->stock += quantity;
        cout << "Compra realizada com sucesso!\n";
    } else {
        cout << "ID de produto invalido.\n";
    }
}


int main() {
    // lista de produtos predefinidos
    vector<Product> products = {
        {1, "Lapis", 0.75, 1.25, 1.25 - 0.75, 50},  
        {2, "Caneta", 1, 1.50, 1.50 - 1, 50},
        {3, "Borracha", 0.70, 1.50, 1.50 - 0.70, 50},
        {4, "Caderno", 2, 5, 5 - 2, 20, 30}
    };

    int choice;
    do {
        cout << "\nEscolha uma acao:\n"
            // << "1. Mostrar esta lista\n"
             << "1. Lista de produtos\n"
             << "2. Adicionar produto a lista\n"
             << "3. Repor stock\n"
             << "0. Sair\n"
             << "Sua opcao: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayProducts(products);
                break;
            case 2:
                addProduct(products);
                break;
            case 3:
                buyProduct(products);
                break;
            case 0:
             cout << "Volte sempre! =D";
                sleep(1); 
                break;


            default:
                cout << " Opcao invalida. Tente novamente.";
        }
    } while (choice != 0);

    return 0;
}
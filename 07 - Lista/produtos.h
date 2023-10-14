#define MAX_PRODUTOS 100

// Definição da estrutura Produto
struct Produto_4
{
    char nomeProduto_4[50];
    float precoUnitario_4;
    int quantidadeEstoque_4;
};

// Função para listar os produtos
void listarProdutos_4(struct Produto_4 produtos_4[], int numProdutos_4)
{
    printf("Produtos cadastrados:\n");
    for (int i = 0; i < numProdutos_4; i++)
    {
        printf("%d. Nome: %s, Preço Unitário: R$%.2f, Estoque: %d\n", i + 1, produtos_4[i].nomeProduto_4, produtos_4[i].precoUnitario_4, produtos_4[i].quantidadeEstoque_4);
    }
}

// Função para buscar um produto por nome
int buscarProduto_4(struct Produto_4 produtos_4[], int numProdutos_4, char nome_4[])
{
    for (int i = 0; i < numProdutos_4; i++)
    {
        if (strcmp(produtos_4[i].nomeProduto_4, nome_4) == 0)
        {
            return i; // Produto encontrado, retorna o índice
        }
    }
    return -1; // Produto não encontrado
}

// Função para excluir um produto
void excluirProduto_4(struct Produto_4 produtos_4[], int *numProdutos_4, int indice_4)
{
    for (int i = indice_4; i < (*numProdutos_4) - 1; i++)
    {
        produtos_4[i] = produtos_4[i + 1];
    }
    (*numProdutos_4)--;
}
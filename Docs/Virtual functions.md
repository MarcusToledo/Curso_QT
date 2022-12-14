# Virtual functions

É utilizada para dizer que queremos que faça a avaliação da chamada dessa função em run-time, não em compile-time como é feito por padrão.

```cpp
#include <iostream>
 
struct base
{
    void funcao()
    {
        std::cout << "chamada da base\n";
    } 
     
    virtual void vfuncao()
    {
        std::cout << "chamada da base\n";
    }
};
 
struct derivada: public base
{
    void funcao()
    {
        std::cout << "chamada da derivada\n";
    } 
     
    void vfuncao()
    {
        std::cout << "chamada da derivada\n";
    }
};
 
int main()
{
    base* pt = new derivada;
     
    //nao virtual
    pt->funcao();
     
    //virtual
    pt->vfuncao();
     
    delete pt;
     
    return 0;
}
```
Saída:
```
chamada da base
chamada da derivada
```
Ou seja, quando uma função-membro (aka. método) é declarada como virtual na classe base, a checagem em run-time é feita e é possível encontrar a vfuncao() na classe derivada, assim chamando a função correta, o que não acontece com funcao(): apesar de ter uma função-membro com mesmo nome na classe derivada, é chamada a funcao() da classe base porque o ponteiro que a referencia é do tipo da classe base. Pra isso serve a keyword virtual.

## Destrutores virtuais
Segue a mesma idéia e com um agrave de risco eminente de **memory leaks!**
Se na classe base não temos o destrutor declarado como virtual, temos um grande problema. Vejamos o exemplo:
```cpp
#include <iostream>
 
class base 
{
    int* ptr;
public:
    base()
    {
        ptr = new int;
    }
     
    ~base() 
    {
        delete ptr;
        std::cout << "'destruindo' base\n";   
    }
};
 
class derivada: public base
{
    int* dptr;
public:
    derivada() {
        dptr = new int;
    }
    ~derivada()
    {
        delete dptr;
        std::cout << "'destruindo' derivada\n";
    }
};
 
int main()
{
    base* pt = new derivada;
    delete pt;
}
```
Saída:
```
'destruindo' base
```
Como podemos ver, apenas o destrutor da classe base é chamado, deletando o ponteiro ptr. Mas e o dptr declarado em derivada e alocado em seu construtor? **Leaked!** Se perdeu!

A solução é declarar o destrutor da classe base como virtual e a mágica acontece.
```cpp
#include <iostream>
 
class base 
{
    int* ptr;
public:
    base()
    {
        ptr = new int;
    }
     
    virtual ~base() 
    {
        delete ptr;
        std::cout << "'destruindo' base\n";   
    }
};
 
class derivada: public base
{
    int* dptr;
public:
    derivada() {
        dptr = new int;
    }
    ~derivada()
    {
        delete dptr;
        std::cout << "'destruindo' derivada\n";
    }
};
 
int main()
{
    base* pt = new derivada;
    delete pt;
}
```
Saída:
```
'destruindo' derivada
'destruindo' base
```

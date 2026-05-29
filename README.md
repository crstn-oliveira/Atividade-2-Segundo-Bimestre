# Repositório – Estruturas de Dados em C

Este repositório contém atividades desenvolvidas na disciplina de Estruturas de Dados utilizando a linguagem C.

Os exercícios envolvem implementação e manipulação de listas encadeadas simples e listas circulares duplamente encadeadas.

---

# Atividade 1 – Lista Encadeada

Foi desenvolvido um gerenciador simples de inteiros usando listas encadeadas. A estrutura permite:
* inserção de elementos no final;
* inserção em posição específica;
* busca de valores;
* inversão da lista;
* divisão da lista em duas partes;
* exibição dos elementos.

## Funções principais

* `criarNo`: cria um novo nó dinamicamente
* `inserirFinal`: adiciona elemento ao final da lista
* `inserirPosicao`: insere elemento em posição específica
* `buscarValor`: busca um valor e retorna sua posição
* `inverterLista`: inverte a ordem da lista
* `dividirLista`: divide a lista em duas metades
* `exibirLista`: exibe todos os elementos

---

# Atividade 2 – Playlist Circular Duplamente Encadeada

Foi implementada uma playlist de músicas utilizando lista circular duplamente encadeada.
A estrutura permite navegação contínua entre as músicas, mantendo a circularidade da playlist e o acesso ao próximo e ao elemento anterior.

Também foi implementado controle de percurso para evitar loops infinitos durante a reprodução da playlist.

## Funções principais

* `adicionarMusica`: adiciona música ao final mantendo a circularidade
* `proximaMusica`: avança para a próxima música
* `musicaAnterior`: retorna para a música anterior
* `exibirPlaylist`: exibe todas as músicas
* `totalMusicas`: retorna a quantidade de músicas
* `tocarPlaylist`: percorre toda a playlist uma única vez
* `liberarPlaylist`: libera a memória utilizada

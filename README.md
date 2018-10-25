# Ordering-automation-system-for-cafeteria-or-restaurant
Ordering automation system for cafeteria / restaurant. Read the README file for more information.

Imagine a seguinte situação. Em uma lanchonete, os pedidos são feitos no caixa e a informação é levada a cozinha de forma manual. Este sistema foi desenvolvido a fim de facilitar esta comunicação. Modo de funcionamento:
Existem dois executáveis operando simultaneamente.

Caixa:
- Realiza os pedidos;
- Coloca o pedido em uma lista encadeada persistente;
- Salva um aquivo txt do pedido na pasta compartilhada com a rede.

Cozinha:
- Lê o pedido compartilhado pela rede na ordem em que chegam as requisições;
- O pedido fica na tela enquanto o usuário não pressiona o "ok" informando que o pedido foi realizado;
- A cor do console muda de acordo com o tempo em espera do programa, sinalizando ao usuário, a demora em realizar o pedido;
- Para trocar a cor do fundo e esperar a entrada simultaneamente, foram utilizados conceitos de Threads e multi processamento.

Trabalho desenvolvido para a disciplina de Programação Estruturada na UNIAN - 2017/1º

Dúvidas ou sugestões: jsimonassi@id.uff.br


///////////////////////////////////////////////////////////////////////////////////////////////////


Imagine the following situation. In a diner, the orders are made in the box and the information is taken to the kitchen by hand. This system was developed in order to facilitate this communication. Operating mode:
There are two executables running simultaneously.

Cashier:
- Make the orders;
- Places the request in a persistent threaded list;
- Save a txt file of the request in the folder shared with the network.

Kitchen:
- Reads the request shared by the network in the order in which the requests arrive;
- The request stays on the screen while the user does not press the "ok" informing that the request was made;
- The color of the console changes according to the waiting time of the program, signaling to the user, the delay in ordering;
- To change the color of the background and wait for input simultaneously, we used Threads and Multi-Processing concepts.

Work developed for the discipline of Structured Programming at UNIAN - 2017 / 1º

Doubts or suggestions: jsimonassi@id.uff.br


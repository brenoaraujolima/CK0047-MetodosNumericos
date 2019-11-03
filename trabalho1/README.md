# CK0047-MetodosNumericos
Implementação do trabalho da disciplina de métodos numéricos I


Tema1:
O deslocamento da extremidade de um foguete espacial ao entrar na atmosfera da terra é dado pela equação f(d) = a*d – d*ln(d), onde d é
o deslocamento medido em cm e a é um parâmetro de ajuste para que se projete um foguete com a máxima segurança e eficiência
possível. Caso esse deslocamento passe dos 2 cm esse foguete irá explodir, causando sérios danos e um prejuízo gigantesco. Vários testes
e simulações são feitos de modo a garantir que o foguete seja desenvolvido com toda segurança possível. Desenvolva um sistema para
calcular esse deslocamento d da extremidade de um foguete espacial considerado com todos os requisitos apresentados nos itens abaixo:<br>
a) Implementar algoritmo para calcular d pelo método da Bisseção.<br>
b) Implementar algoritmo para calcular d pelo método da Posição Falsa.<br>
c) Implementar algoritmo para calcular d pelo método de Newton-Raphson.<br>
d) Calibrar o sistema usando como padrão a = 1, isolamento = (2, 3) e ε = 10^-5
.<br>
e) Fornecer um quadro resposta, variando os valores de a para vários foguetes.<br>
f) Fornecer um quadro comparativo, com isolamento, raízes e dados para cada método.<br>
g) Analisar o efeito da variação do valor de a de cada foguete, para cada método dado.<br>
<b>Dados de entrada:</b> n (número de foguetes), a (de cada foguete) e ε (precisão).<br>
<b>Dados de saída:</b> quadros resposta (com d, EA para cada foguete e método) e comparativo

Compilar no linux:<br>
<code>g++ main.cpp Metodos.cpp Interface.cpp -o main</code><br>
para executar<br>
<code>./main</code>

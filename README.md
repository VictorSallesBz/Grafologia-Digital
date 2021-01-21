# Grafologia Digital

Grafologia Digital é um sistema que identificará o usuário que está digitando e verificará se possui o registro de um usuário que corresponda a sua maneira de digitar.

### 2 Tipos de funcionamento:

  - Autenticação
  - Escrita Geral


##### Autenticação
  - O usuário cadastrará sua senha para armazenar sua maneira de digitação da senha.
  
##### Escrita Geral
  - O usuário será monitorado o tempo todo com o sistema extraindo seus dados de escrita.
  - Quando o sistema perceber que houve uma mudança repentina no jeito de digitação, pedirá que o usuário se autentique novamente.
  
### Tipos de detecção

##### Gangorra
- Será criado um vetor que armazenará se a digitação da tecla foi mais rápido ou mais lenta que a anterior.
- O vetor armazenará 1 para mais rápido e 0 para mais lento.
- A verificação será feita comparando o vetor salvo com o vetor digitado.

#### Velocidade
- Será armazenado a velocidade que o usuário digita a tecla.
- Será feito um estudo para determinar um limiar para mais ou para menos.
- A verificação será feita comparando a velocidade digitada com a velocidade salva + ou - o limiar.
- Se a velocidade digitada estiver no limiar, será aceito, caso contrário, será recusado.

#### Tempo Total
- Será armazenado o tempo médio que o usuário digita a senha.
- Será feito um estudo para determinar um limiar para mais ou para menos.
- A verificação será feita comparando o tempo da digitação com o tempo salvo + ou - o limiar.
- Se o tempo estiver dentro do limiar, será aceito, caso contrário, será recusado.

#### Levenshtein
- Será armazenado um caracter para cada faixa de tempo de digitação.
- Por exemplo: de 0ms - 60ms = a; 61 - 80ms = b; 81 - 90ms = c...
- A verificação será feita comparando as strings geradas através do algoritmo de Levenshtein.

O sistema terá níveis de segurança, deixando o sistema mais rígido ou liberal com as comparações além de um limiar maior ou menor.
Eu continuo pensando em novas formas de verificação. Sinta-se a vontade em me ajudar :P

## Armazenação da digitação
- Para as senhas, será armazenado vetores com os dados de cada etapa de verificação.
- Os dados da digitação em geral, será em uma matriz onde os índices de linhas e colunas serão o número do caracter na tabela ASCII.
- Os caracteres das linhas representam a última tecla, enquanto os caracteres das colunas a nova tecla digitada.
- Por exemplo: Digitei "Top". T = 84; o = 111 e p = 112 na tabela ASCII.
- Logo será armazenado os tempo de digitação na matriz da seguinte forma.
- O tempo de T será armazenado na linha 84 e coluna 84 já que não houve tecla digitada antes dele.
- O tempo de o será armazenado na linha 84 e coluna 111, pois ele foi digitado após a letra T.
- O tempo de p será armazenado na linha 111 e na coluna 112...
- Caso uma casa da matriz já possua um valor, será feito uma média com o novo tempo.


Por enquanto é isso. Vou desenvolvendo quando der e anotando quando tiver novas ideias. Vlw meu povo!

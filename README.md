# Descrição do Projeto 
O obetivo do deste trabalho é implementar um pequeno programa em C++, usando um projeto Code::Blocks.

# Especificação do Projeto 
A meta da implementação é a construção do programa seguindo os seguintes critérios:
- O programa deve ser corretamente modularizado, usando Orientação a Objetos (dividindo em classses, métodos, etc.);
- O projeto deve ser criado da seguinte forma: nome1-nome2-nome3, onde nome1,nome2,nome3 devem ser substituidos pelos nomes dos menbros do grupo.
- No cabeçalho do arquivo, deve constar um comentário com a identificação completa dos menbros do grupo, incluindo o número de matrícula.
- Ao términio do trabalho, cada grupo deverá:
    - Selecionar a opção Clean do menu Build, no Code::Blocks;
    - Compactar a pasta do projeto com todo seu conteúdo, usando o mesmo nome da pasta como nome do arquivo (ex.: nome1-nome2-nome3-nome4.zip)


## O objetivo desse trabalho é implementar um servidor de echo reverso. Seu servidor: 
- Deverá criar um socket de conexão quando contactado por um cliente telnet na porta 5000.
- O cliente enviará uma única string  que será finalizada com um quebra de linha.
- O servidor deverá retornar essa string ao cliente (echo) com os caracteres invertidos (reversão da string), por exemplo "bom dia" deve ser retornado como "aid mob".

## Além disso, considere as seguintes recomendações, para tornar o trabalho mais viável:
- A API de Sockets do Linux é um pouco complexa, observe no livro texto características que viabilizem a implementação de uma classe ServerSocket que torne o atendimento mais rápido e com menos repetição de código.
- Utilize a biblioteca thread disponível a partir da versão C++11, para evitar usar as APIs nativas de threads.

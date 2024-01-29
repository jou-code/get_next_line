# get_next_line

Função que retorna sempre a próxima linha de um arquivo.
<br></br>
<br></br>

### Principais tópicos de estudo:
- File descriptor
- Variáveis estáticas
- Read( )
- Memória; Malloc( ) e Free( )
<br></br>

### Qual é a utilidade da GNL?
texto
<br></br>

<details><summary><h3>⚠️ Spoiler! Sobre a função:</h3></summary>
  A partir do file descriptor, a string que será retornada é lida do arquivo com read( ), de acordo com o tamanho do buffer passado, e armazenada numa variável estática que serve de acumulador até achar a quebra de linha ou o fim do arquivo. Ao achar a linha, ela é retornada, e a variável estática guarda apenas o que foi lido para além dessa linha (se houver algo).</details>



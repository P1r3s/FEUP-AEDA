# FEUP-AEDA

## Tema 2 – Aluguer de Campos de Ténis

### Parte 1

Uma empresa municipal possui campos de ténis que disponibiliza aos seus utentes para uso em dois modos:
modo de aula (duração de 1h com professor) e modo livre (duração até 2h sem professor: para simplificar,
considere períodos múltiplos de 30 minutos). Existe um número máximo de utentes que podem estar em
simultâneo nos campos de ténis. As aulas têm prioridade no uso do campo, pelo que o número de utentes
admissível em modo livre em cada período é igual a (NumMaximoUtentes - NumUtentesAula).
O preço de uso do campo de ténis é: fixo, em modo aula; e fixo por período de 30 minutos em modo livre.
A empresa possui um cartão gold com um custo fixo mensal que permite o acesso a aulas com 15% desconto no
valor unitário da aula.
O sistema a implementar deve registar todas as ocorrências em que um utente usa os campos, incluindo a data.
No final do mês, o utente deve pagar o uso dos campos nesse mês, sendo-lhe entregue um documento onde são
discriminadas todas as datas/horas em que frequentou os campos.Os utentes que usaram os campos em modo
de aula têm ainda acesso a um relatório mensal sobre o seu progresso elaborado pelo professor. As aulas são
lecionadas pelos professores existentes, sendo o professor de determinada aula escolhido de modo a equilibrar o
número de aulas por professor.
O sistema deve permitir a consulta da ocupação dos campos de ténis, frequência de utentes, contas dos utentes,
aulas leccionadas por professores, horário de aulas, horário de professores. (nota: esta enumeração de listagens a
implementar não é exaustiva).

### Parte 2

Complementar o sistema já implementado com as seguintes funcionalidades:

- [x] &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;A empresa municipal pretende manter um registo de todos os utentes dos campos de ténis que já usaram os serviços da empresa. Guarde numa árvore binária de pesquisa  os utentes dos campos de ténis, ordenados pelo número de vezes que usaram os campos (aula ou livre) e, em caso de empate, por ordem alfabética. A identificação do utente deve ainda incluir a morada do mesmo e o NIF. 
- [x] &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Os campos de ténis precisam frequentemente de intervenções e melhorias de forma a manter os níveis de qualidade definidos pela empresa municipal. Para tal, a empresa recorre aos serviços de técnicos especializados que são guardados numa fila de prioridade ordenada pela disponibilidade dos técnicos (a disponibilidade é um valor inteiro que indica o número de dias em falta até que o técnico esteja disponível). O técnico que está no topo é o que estará disponível mais cedo. De forma a cumprir com procedimentos de contratação pública, que limitam o número de vezes que a empresa pode recorrer aos serviços de um dado técnico, para além da disponibilidade, o técnico é também caracterizado pelo número de reparações já efetuadas. Para a reparação de um campo de ténis, deve ser escolhido o técnico disponível mais cedo e que tenha concluído menos do que um número de reparações a especificar. Considere, por simplificação, que a reparação de um campo demora sempre 1 dia, devendo a disponibilidade do técnico ser atualizada. 
- [x] &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;A empresa mantém um registo de todos os seus professores (atuais ou antigos) numa tabela de dispersão. A manutenção do registo de professores antigos da empresa justifica-se porque, no caso de necessidade de contratação de novos professores, a empresa tem como política interna a contratação de professores já conhecidos. O professor deve estar associado às aulas que realiza (se é um trabalhador atual da empresa).

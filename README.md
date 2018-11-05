# FEUP-AEDA
Tema 2 – Aluguer de Campos de Ténis (Parte 1)

### Enunciado

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

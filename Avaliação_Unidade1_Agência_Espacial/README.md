# Projeto Agência Espacial Brasileira Digital

Este projeto consiste em um sistema de gerenciamento de astronautas e voos espaciais, permitindo o controle completo desde o cadastro até a finalização (sucesso ou explosão) das missões.

## Funcionalidades
- **Cadastro de Astronautas:** Controle por CPF, nome e idade.
- **Gerenciamento de Voos:** Planejamento, lançamento e finalização de missões.
- **Segurança de Dados:** Validação de CPFs duplicados, estados de voo e disponibilidade de astronautas.
- **Relatórios:** Listagem de voos por categoria e histórico de astronautas mortos em missões.

## Compilação e Execução

Para compilar o projeto, utilize um compilador C++ (como o G++):

```bash
g++ main.cpp -o agencia
```

### Execução no Windows (PowerShell/CMD)

O sistema foi configurado para suportar caracteres UTF-8 no terminal do Windows. Para rodar manualmente:

```
./agencia
```

### Testes Automatizados

Para facilitar a correção e validar todos os fluxos do sistema (mensagens de erro, sucesso e listagens), incluí um arquivo de script de teste sequencial que perpassa todas as possibilidades de entrada no sistema. Para rodar todos os comandos de uma vez usando o pipe:

No PowerShell:
```
Get-Content teste_sequencial_total.txt | ./agencia
```

No CMD ou Linux:
```
./agencia < teste_sequencial_total.txt
```

##
### Assistência no Desenvolvimento
Este projeto contou com o apoio auxiliar do **Gemini 3 Flash (Google)** para a estruturação de roteiros de testes automatizados, depuração de erros de compilação em ambiente Windows (UTF-8), revisão da lógica de loops aninhados e ajustes finos na documentação e organização do repositório no GitHub.

##
**Desenvolvido por Sibelle Galina.**
##### Este projeto faz parte das atividades práticas avaliativas da disciplina de Linguagem de Programação I (IMD/UFRN).


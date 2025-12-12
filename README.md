# Minitalk

<div align="center">

![So Long](https://img.shields.io/badge/42-São_Paulo-0056D2?style=for-the-badge&logo=42&logoColor=white)
![Language](https://img.shields.io/badge/C-A8B9CC?style=for-the-badge&logo=c&logoColor=black)
![License](https://img.shields.io/badge/License-MIT-32CD32?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)
![Version](https://img.shields.io/badge/Version-1.0.0-blue?style=for-the-badge)

</div>

<div align="center">

![GitHub repo size](https://img.shields.io/github/repo-size/ZimboSebastiao/minitalk?style=flat-square&color=0056D2)
![GitHub last commit](https://img.shields.io/github/last-commit/ZimboSebastiao/minitalk?style=flat-square&color=32CD32)
![GitHub issues](https://img.shields.io/github/issues/ZimboSebastiao/minitalk?style=flat-square&color=orange)
</div>

## Sobre o Projeto

**Minitalk** é um projeto da 42 São Paulo que implementa um sistema de comunicação cliente-servidor utilizando **sinais UNIX** como meio de transmissão. O projeto demonstra comunicação inter-processos (IPC) em baixo nível, onde dados são transmitidos bit a bit usando apenas dois sinais: `SIGUSR1` e `SIGUSR2`.

## Funcionalidades

### Funcionalidades Obrigatórias
- [x] **Servidor** que exibe seu PID ao iniciar
- [x] **Cliente** que recebe PID e string como parâmetros
- [x] Transmissão de strings via sinais UNIX
- [x] Recebimento e exibição imediata no servidor
- [x] Suporte a múltiplos clientes sequenciais
- [x] Uso exclusivo de `SIGUSR1` e `SIGUSR2`
- [x] Sem vazamentos de memória
- [x] Tratamento completo de erros

### ⚡ Performance
- Transmissão de 100 caracteres em menos de 1 segundo
- Sistema de confirmação bit a bit
- Otimizado para evitar perda de sinais


## 🔧 Instalação e Compilação

### 🚀 Compilação Rápida

#### Clone o repositório

```bash
git clone https://github.com/ZimboSebastiao/minitalk.git
cd minitalk
```
#### Compile tudo

```bash
make
```

###  Comandos do Makefile

| Comando | Descrição |
|---------|-----------|
| `make` ou `make all` | Compila cliente e servidor |
| `make clean` | Remove arquivos objeto |
| `make fclean` | Remove objetos e executáveis |
| `make re` | Recompila completamente |


## Como Usar

### Passo 1: Iniciar o Servidor

```bash
# Terminal 1
./server
```

**Saída:**
```
🚀 Servidor iniciado!
📡 PID do servidor: 12345
⏳ Aguardando mensagens...
```

### Passo 2: Enviar Mensagem do Cliente
```bash
# Terminal 2 (substitua 12345 pelo PID real)
./client 12345 "Olá Mundo!"
```

**Saída do Cliente:**
```
📤 Enviando mensagem para o servidor PID 12345
📝 Mensagem: Olá Mundo!
✅ Mensagem enviada com sucesso!
```

**Saída do Servidor:**
```
Olá Mundo!
```

### Teste de Performance
```bash
# Teste com 100 caracteres
./client $PID "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore."

# Verifique se leva menos de 1 segundo
time ./client $PID "x"  # Caractere único
```

### Teste de Estresse
```bash
# Múltiplas mensagens rápidas
for i in {1..10}; do
    ./client $PID "Mensagem $i"
done

# Mensagem muito longa (1000+ caracteres)
./client $PID "$(cat /dev/urandom | tr -dc 'a-zA-Z0-9' | fold -w 1000 | head -n 1)"
```

## Valgrind (Detecção de Vazamentos)

### Testando o Servidor
```bash
# Executar servidor com valgrind
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./server

# Em outro terminal, envie mensagens
./client [PID] "Teste de vazamento"

# Para parar o servidor
kill [PID]
```

### Testando o Cliente
```bash
# Inicie o servidor primeiro
./server & SERVER_PID=$!

# Teste o cliente com valgrind
valgrind --leak-check=full --show-leak-kinds=all ./client $SERVER_PID "Teste"

# Limpeza
kill $SERVER_PID
```

### 🔧 Comandos Úteis do Valgrind

| Comando | Descrição |
|---------|-----------|
| `--leak-check=full` | Verificação completa de vazamentos |
| `--show-leak-kinds=all` | Mostra todos os tipos de vazamentos |
| `--track-origins=yes` | Rastreia origem de valores não inicializados |
| `--verbose` | Saída detalhada |
| `--log-file=valgrind.log` | Salva saída em arquivo |


<div align="center">

### 📞 Contato

[![Email](https://img.shields.io/badge/Email-D14836?style=for-the-badge&logo=gmail&logoColor=white)](mailto:gloriasebastiao7@gmail.com)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/zimbo-sebasti%C3%A3o-3397a1195/)

### 🌟 Dê uma estrela!

Se este projeto foi útil para você, considere dar uma estrela ⭐

[![GitHub stars](https://img.shields.io/github/stars/ZimboSebastiao/minitalk?style=social)](https://github.com/ZimboSebastiao/minitalk)

---

**Minitalk** • Projeto 42 São Paulo • Desenvolvido com 💙

</div>
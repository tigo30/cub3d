depois fica a faltar:

inicializar a estrutura exemplo "t_data" (como o sistema gráfico, janela, texturas, jogador, etc.).


implementar a captura de eventos do teclado.
Define as ações para cada tecla relevante, como mover o jogador, fechar o jogo, etc.

game:
Cria a lógica principal do jogo:
Atualizar o estado do jogo (posição do jogador, renderização, etc.).
Renderizar o cenário e os elementos na janela.
Lidar com colisões ou interações no mapa.
mlx_loop_hook e mlx_loop:

O mlx_loop_hook deve ser configurado para chamar a função que atualiza e desenha o jogo em cada frame.
O mlx_loop inicia o loop principal da biblioteca MiniLibX, mantendo a aplicação gráfica ativa.

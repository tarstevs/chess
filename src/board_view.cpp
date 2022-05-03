#include "board_view.h"

board_view::board_view(const sf::Event &event, sf::RenderWindow &render_window)
    : event(event), render_window(render_window) {}

void board_view::configure_and_set_view() {
  auto w = static_cast<float>(event.size.width);
  auto h = static_cast<float>(event.size.height);
  view.setSize({w, h});
  view.setCenter({
                     w / 2.f, h / 2.f});
  render_window.setView(view);
}
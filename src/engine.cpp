#include "engine.hpp"

#include <stdexcept>

#include "component.hpp"
#include "stack_allocator.hpp"

ecs::Engine* ecs::Engine::instance_ = nullptr;

ecs::Engine& ecs::Engine::Instance() {
  if (instance_ == nullptr) {
    throw std::logic_error("Engine is not initialized.");
  }

  return *instance_;
}

void ecs::Engine::Initialize(std::size_t max_components_per_types) {
}

ecs::Engine::Engine(unsigned char* memory_arena, const uint64_t& memory_size_bytes,
                    const std::size_t& max_components_per_type)
    : memory_size_bytes_(memory_size_bytes),
      max_components_per_type_(max_components_per_type),
      allocator_(memory_arena, memory_size_bytes),
      pool_allocators_(max_components_per_type, nullptr) {

}

ecs::EntityId ecs::Engine::CreateEntity() {
  return EntitiesManager::Instance().CreateEntity();
}

void ecs::Engine::MakeTic() {
  SystemsManager::Instance().PreUpdate();
  SystemsManager::Instance().Update();
  SystemsManager::Instance().PostUpdate();
}

void ecs::Engine::SetUp() {
  SystemsManager::Instance().SetUp();
}

void ecs::Engine::ShutDown() {
}

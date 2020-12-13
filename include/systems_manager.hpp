#ifndef ECS_INCLUDE_SYSTEMS_MANAGER_HPP_
#define ECS_INCLUDE_SYSTEMS_MANAGER_HPP_

#include <vector>
#include <stdexcept>

#include "system.hpp"

namespace ecs {

class SystemsManager {
 public:
  static SystemsManager& Instance();

  static void Initialize();

  void AddSystem(System* system);
  void AddDependency(System* dependent, System* independent);
  void PreUpdate();
  void Update();
  void PostUpdate();

 private:
  explicit SystemsManager(std::size_t& number_of_system_types);
  explicit SystemsManager(const SystemsManager& other) = delete;

  void FindTopologicalOrder();
  void Dfs(std::vector<char> color, std::size_t source);

  static SystemsManager* instance_;

  const std::size_t kNumberOfSystemTypes;

  std::vector<std::vector<size_t>> dependency_graph_;
  std::vector<System*> systems_;
  std::vector<System*> systems_topological_order_;
};

}  // namespace ecs

#endif  // ECS_INCLUDE_SYSTEMS_MANAGER_HPP_

import os

from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps
from conan.tools.files import copy

class MyConanFile(ConanFile):
  name = "dreich"
  version = "1.0"
  settings = "os", "compiler", "build_type", "arch"
  generators = "CMakeDeps", "CMakeToolchain"
  exports_sources = "*"

  options = {
   
  }

  default_options = {
    "fmt/*:header_only": True,
  }

  def requirements(self):
    self.requires("sdl/2.30.8")
    self.requires("catch2/3.7.1")
    self.requires("fmt/11.0.2")

  def build(self):
    cmake = CMake(self)
    cmake.configure()
    cmake.build()

  def deploy(self):
    copy(self, "*", src=self.package_folder, dst=self.deploy_folder)

  def layout(self):
    cmake_layout(self)
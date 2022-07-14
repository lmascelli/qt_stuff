function build
{
  if (Test-Path -Path "build")
  {
    Push-Location "build"
    cmake -G"Ninja" -DCMAKE_EXPORT_COMPILE_COMMANDS=True -DQt6_DIR="D:/Qt/6.3.0/mingw_64" ..
    cmake --build .
    Move-Item -Path "compile_commands.json" -Destination ".." -ErrorAction Ignore -Force
    Pop-Location
  } else
  {
    New-Item -Path "build" -ItemType Directory
    Copy-Item -Path "..\bin\*.dll" -Destination "build"
    Copy-Item -Path "..\bin\platforms" -Destination "build" -Recurse
    build
  }
}

function clean
{
  Remove-Item -Path "build" -Force -Recurse
}

function run
{
  build
  Push-Location "build"
  Start-Process -FilePath ".\shooter.exe"
  Pop-Location
}

Clear-Host

if ($args[0])
{
  switch($args[0])
  {
    "build"
    {
      build
    }
    "clear"
    {
      clean
    }
    "run"
    {
      run
    }
  }
}

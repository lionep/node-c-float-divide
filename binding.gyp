{
  "targets": [
    {
      "target_name": "addon",
      "sources": [ "src/main.cc" ],
      "include_dirs": ["<!(node -e \"require('nan')\")"]
    }
  ]
}

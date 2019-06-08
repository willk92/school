Write-Host "$args"

$args.ToCharArray() | %{[int][char]$_}
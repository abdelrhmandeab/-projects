from audio.mic import record_until_silence
from audio.stt import transcribe
from core.command_router import route_command

record_until_silence()
text = transcribe("input.wav")
print("User:", text)
print("Jarvis:", route_command(text))
